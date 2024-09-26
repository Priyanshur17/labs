#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define ITERATIONS 1000000

int sharedCounter = 0;
pthread_mutex_t mutex;

void *raceCondition(void *threadID) {
    int tid = *((int *)threadID);
    
    for (int i = 0; i < ITERATIONS; i++) {
        // Simulate some computation
        usleep(1);

        // Without mutex (race condition)
        sharedCounter++;

        // With mutex (no race condition)
        // pthread_mutex_lock(&mutex);
        // sharedCounter++;
        // pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        exit(1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i;

        if (pthread_create(&threads[i], NULL, raceCondition, &threadIDs[i]) != 0) {
            perror("Thread creation failed");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(1);
        }
    }

    printf("Final sharedCounter value: %d\n", sharedCounter);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

