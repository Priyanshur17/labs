//Exercise 4: Implement the following scenario in openMP.
//Using condition variables to implement a producer-consumer algorithm. Define two threads: one
//producer and one consumer. The producer reads characters one by one from a string stored in a
//file named “string.txt”, then writes sequentially these characters into a circular queue.
//Meanwhile, the consumer reads sequentially from the queue and prints them in the same order.
//The diagram illustrates the process. Upon completion of running the program, “Hello! World.” is
//printed on the screen. In the program, use #define to specify the size of the queue. For example,
//#define QUEUE_SIZE 5. Make sure to test your program with different queue sizes, including 1.


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define QUEUE_SIZE 5

char circular_queue[QUEUE_SIZE];
int front = 0, rear = 0, count = 0;

omp_lock_t lock;
omp_cond_t producer_cond, consumer_cond;

void enqueue(char item) {
    circular_queue[rear] = item;
    rear = (rear + 1) % QUEUE_SIZE;
    count++;
}

char dequeue() {
    char item = circular_queue[front];
    front = (front + 1) % QUEUE_SIZE;
    count--;
    return item;
}

void producer_function() {
    FILE* file = fopen("string.txt", "r");
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        omp_set_lock(&lock);

        while (count == QUEUE_SIZE) {
            omp_cond_wait(&producer_cond, &lock);
        }

        enqueue(ch);
        printf("Producing: %c\n", ch);

        omp_cond_signal(&consumer_cond);
        omp_unset_lock(&lock);
    }

    fclose(file);
}

void consumer_function() {
    while (1) {
        omp_set_lock(&lock);

        while (count == 0) {
            omp_cond_wait(&consumer_cond, &lock);
        }

        char ch = dequeue();
        printf("Consuming: %c\n", ch);

        omp_cond_signal(&producer_cond);
        omp_unset_lock(&lock);
    }
}

int main() {
    omp_init_lock(&lock);
    omp_init_cond(&producer_cond);
    omp_init_cond(&consumer_cond);

    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                producer_function();
            }

            #pragma omp section
            {
                consumer_function();
            }
        }
    }

    return 0;
}

