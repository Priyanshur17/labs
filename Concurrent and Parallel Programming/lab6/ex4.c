
#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<unistd.h>

#define QUEUE_SIZE 10
char buffer[QUEUE_SIZE];

int itemCount = 0; // Number of items in the buffer
int in = 0;        // Index where the producer will insert the next item
int del = 0;       // Index where the consumer will remove the next item

// Function to simulate a producer adding an item to the buffer
void producer(FILE*ptr) {
    char item;
    while (fgetc(ptr)!=EOF) {
        item=fgetc(ptr);
        #pragma omp critical
        {
            if (itemCount < QUEUE_SIZE) {
                buffer[in] = item;
                in = (in + 1) % QUEUE_SIZE;
                itemCount++;
                printf("Produced: %c and itemcount is %d\n", item,itemCount);
            }
        }
    }
}

// Function to simulate a consumer removing an item from the buffer
void consumer(FILE*ptr) {
    char item;
    while (itemCount>0) {
        item=buffer[del];
        printf("%c",item);       
        #pragma omp critical
        {
            if (itemCount > 0) {
                item = buffer[del];
                
                del = (del + 1) % QUEUE_SIZE;
                itemCount--;
                printf("Consumed: %d and itemcount is %d\n", item,itemCount);
            }
        }
    }
    
}

int main() {
    FILE* file = fopen("string.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fgets(buffer, QUEUE_SIZE, file);
    fclose(file);
    #pragma omp parallel num_threads(2)
    {
        int threadId = omp_get_thread_num();
        if (threadId == 0) {
            producer(file);
        } else if (threadId == 1) {
            consumer(file);
        }
    }

    return 0;
}


