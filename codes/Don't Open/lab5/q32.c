#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10001

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    double sum = 0.0;

    printf("Thread %d starting...\n", thread_id);

    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        sum += sin(i) + tan(i);
    }

    printf("Thread %d done. Result = %e\n", thread_id, sum);

    int *status = (int *)malloc(sizeof(int));
    *status = thread_id;
    pthread_exit(status);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    int thread_ids[NUM_THREADS];
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < NUM_THREADS; ++i) {
        printf("Main: creating thread %d\n", i);
        thread_ids[i] = i;
        pthread_create(&threads[i], &attr, thread_function, (void *)&thread_ids[i]);
    }

    pthread_attr_destroy(&attr);

    void *thread_status;
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], &thread_status);
        printf("Main: completed join with thread %d having a status of %d\n", i, *((int *)thread_status));
        free(thread_status);
    }

    printf("Main: program completed. Exiting.\n");

    pthread_exit(NULL);
}

