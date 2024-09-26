#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define QUEUE_SIZE 5

char buffer[QUEUE_SIZE];
int in = 0, out = 0, count = 0;
int end_of_file = 0;

void produce(const char* str) {
    #pragma omp critical
    {
        if (count < QUEUE_SIZE) {
            buffer[in] = str[count];
            in = (in + 1) % QUEUE_SIZE;
            count++;
        }
    }
}

char consume() {
    char item = '\0';
    #pragma omp critical
    {
        if (count > 0) {
            item = buffer[out];
            out = (out + 1) % QUEUE_SIZE;
            count--;
        }
    }
    return item;
}

int main() {
    FILE* file = fopen("string.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char input[QUEUE_SIZE];
    fgets(input, QUEUE_SIZE, file);
    fclose(file);

    // Create two threads, one for producing and one for consuming
    #pragma omp parallel num_threads(2)
    {
        int thread_id = omp_get_thread_num();
        if (thread_id == 0) { // Producer
            for (int i = 0; i < QUEUE_SIZE; i++) {
                produce(input);
            }
        } else if (thread_id == 1) { // Consumer
            while (end_of_file == 0) {
                char item = consume();
                if (item != '\0') {
                    printf("%c", item);
                } else {
                    end_of_file = 1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <omp.h>

// #define QUEUE_SIZE 5

// char circularQueue[QUEUE_SIZE];
// int front = 0, rear = 0, count = 0;
// int done_producing = 0;
// int done_consuming = 0;
// omp_lock_t queue_lock;
// omp_cond_t not_full, not_empty;

// void enqueue(char item) {
//     circularQueue[rear] = item;
//     rear = (rear + 1) % QUEUE_SIZE;
//     count++;
// }

// char dequeue() {
//     char item = circularQueue[front];
//     front = (front + 1) % QUEUE_SIZE;
//     count--;
//     return item;
// }

// void producer() {
//     FILE *file = fopen("string.txt", "r");
//     char ch;
//     while ((ch = fgetc(file)) != EOF) {
//         omp_set_lock(&queue_lock);
//         while (count == QUEUE_SIZE) {
//             // Queue is full, wait for it to become not full
//             omp_cond_wait(&not_full, &queue_lock);
//         }
//         enqueue(ch);
//         printf("Producer: Enqueued '%c'\n", ch);
//         omp_cond_signal(&not_empty);
//         omp_unset_lock(&queue_lock);
//     }
//     done_producing = 1;
//     fclose(file);
// }

// void consumer() {
//     while (!done_producing || count > 0) {
//         omp_set_lock(&queue_lock);
//         while (count == 0 && !done_producing) {
//             // Queue is empty, wait for it to become not empty
//             omp_cond_wait(&not_empty, &queue_lock);
//         }
//         if (count > 0) {
//             char ch = dequeue();
//             printf("Consumer: Dequeued '%c'\n", ch);
//             omp_cond_signal(&not_full);
//         }
//         omp_unset_lock(&queue_lock);
//     }
//     done_consuming = 1;
// }

// int main() {
//     omp_init_lock(&queue_lock);
//     omp_init_cond(&not_full);
//     omp_init_cond(&not_empty);

//     #pragma omp parallel sections
//     {
//         #pragma omp section
//         {
//             producer();
//         }

//         #pragma omp section
//         {
//             consumer();
//         }
//     }

//     while (!done_consuming) {
//         // Wait for the consumer to finish
//     }

//     omp_destroy_lock(&queue_lock);
//     omp_destroy_cond(&not_full);
//     omp_destroy_cond(&not_empty);

//     return 0;
// }
