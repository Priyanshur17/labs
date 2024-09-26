#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int itemCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        int item = rand() % 100;  

        pthread_mutex_lock(&mutex);

        while (itemCount == BUFFER_SIZE) {
            pthread_cond_wait(&bufferNotFull, &mutex);
        }

        buffer[itemCount] = item;
        itemCount++;
        printf("Produced: %d\n", item);

        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&bufferNotEmpty);
    }
    
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        while (itemCount == 0) {
            pthread_cond_wait(&bufferNotEmpty, &mutex);
        }

        int item = buffer[itemCount - 1];
        itemCount--;
        printf("Consumed: %d\n", item);

        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&bufferNotFull);
    }

    pthread_exit(NULL);
}

int main() {
   

    pthread_t producerThreads[2];
    pthread_t consumerThreads[2];

    for (int i = 0; i < 2; i++) {
        pthread_create(&producerThreads[i], NULL, producer, NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_create(&consumerThreads[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(producerThreads[i], NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    return 0;
}
     

