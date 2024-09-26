#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int itemCount = 0; 
int in = 0;       
int out = 0;     

// Function to simulate a producer adding an item to the buffer
void producer() {
    int item;
    int i =0;
    while (i<20) {
        item = rand() % 100; // Simulate producing an item
        #pragma omp critical
        {
            if (itemCount < BUFFER_SIZE) {
                buffer[in] = item;
                in = (in + 1) % BUFFER_SIZE;
                itemCount++;
                printf("Produced: %d\n", item);
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
                item = buffer[out];
                out = (out + 1) % BUFFER_SIZE;
                itemCount--;
                printf("Consumed: %d\n", item);
            }
        }
     i++;
    }
}

int main() {

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


