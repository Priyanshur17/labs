#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
int itemCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        int item = rand() % 100;  // Generate a random item

        pthread_mutex_lock(&mutex);

        if (itemCount < BUFFER_SIZE) {
            buffer[itemCount] = item;
            itemCount++;
            printf("Produced: %d\n", item);
        } else {
            printf("Buffer is full. Producer waiting.\n");
        }

        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        if (itemCount > 0) {
            int item = buffer[itemCount - 1];
            itemCount--;
            printf("Consumed: %d\n", item);
        } else {
            printf("Buffer is empty. Consumer waiting.\n");
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    pthread_t producerThreads[NUM_PRODUCERS];
    pthread_t consumerThreads[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producerThreads[i], NULL, producer, NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumerThreads[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producerThreads[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    return 0;
}

