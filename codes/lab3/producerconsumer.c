#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

pthread_mutex_t mutex;
pthread_cond_t empty, full;

void produce(int item) {
    pthread_mutex_lock(&mutex);
    while (((in + 1) % BUFFER_SIZE) == out) {
        // Buffer is full, wait for a consumer to consume
        pthread_cond_wait(&empty, &mutex);
    }

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    printf("Produced: %d\n", item);

    // Signal that the buffer is no longer empty
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
}

int consume() {
    int item;

    pthread_mutex_lock(&mutex);
    while (in == out) {
        // Buffer is empty, wait for a producer to produce
        pthread_cond_wait(&full, &mutex);
    }

    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    printf("Consumed: %d\n", item);

    // Signal that the buffer is no longer full
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);

    return item;
}

void* producer(void* arg) {
    for (int i = 0; i < 10; i++) {
        produce(i);
        usleep(100000);  // Sleep for a short time
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        int item = consume();
        usleep(100000);  // Sleep for a short time
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&empty, NULL);
    pthread_cond_init(&full, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&empty);
    pthread_cond_destroy(&full);

    return 0;
}

