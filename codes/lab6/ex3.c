#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];

int itemCount = 0; // Number of items in the buffer
int in = 0;        // Index where the producer will insert the next item
int del = 0;       // Index where the consumer will remove the next item

// Function to simulate a producer adding an item to the buffer
void producer() {
    int item;
    int i=0;
    while (i<20) {
        item = rand() % 100; // Simulate producing an item
        #pragma omp critical
        {
            if (itemCount < BUFFER_SIZE) {
                buffer[in] = item;
                in = (in + 1) % BUFFER_SIZE;
                itemCount++;
                printf("Produced: %d and itemcount is %d\n", item,itemCount);
            }
        }
      i++;
    }
}

// Function to simulate a consumer removing an item from the buffer
void consumer() {
    int item;
    int i=0;
    while (i<20) {
        #pragma omp critical
        {
            if (itemCount > 0) {
                item = buffer[del];
                del = (del + 1) % BUFFER_SIZE;
                itemCount--;
                printf("Consumed: %d and itemcount is %d\n", item,itemCount);
            }
        }
    i++;
    }
}

int main() {
    // Initialize OpenMP parallel region with two threads
    #pragma omp parallel num_threads(2)
    {
        int threadId = omp_get_thread_num();

        if (threadId == 0) {
            producer();
        } else if (threadId == 1) {
            consumer();
        }
    }

    return 0;
}
