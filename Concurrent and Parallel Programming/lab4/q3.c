// Write a thread program which demonstrates how to "wait" for thread completions by
// using the Pthread join routine. Since some implementations of Pthreads may not create
// threads in a joinable state, therefore explicitly created attribute in a joinable state so that
// they can be joined later. Created thread should perform the calculation of sum =sum +
// sin(i) + Tan(i), where i =0 to 10000. Print the out in the following manner

// Main: creating thread 0
// Main: creating thread 1
// Thread 0 starting...
// Main: creating thread 2
// Thread 1 starting...
// Main: creating thread 3
// Thread 2 starting...
// Thread 3 starting...
// Thread 1 done. Result = -3.153838e+06
// Thread 0 done. Result = -3.153838e+06
// Main: completed join with thread 0 having a status of 0
// Main: completed join with thread 1 having a status of 1
// Thread 3 done. Result = -3.153838e+06
// Thread 2 done. Result = -3.153838e+06
// Main: completed join with thread 2 having a status of 2
// Main: completed join with thread 3 having a status of 3
// Main: program completed. Exiting.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10001

double thread_results[NUM_THREADS];

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    double sum = 0.0;

    printf("Thread %d starting...\n", thread_id);

    for (int i = thread_id; i < NUM_ITERATIONS; i += NUM_THREADS) {
        sum += sin(i) + tan(i);
    }

    thread_results[thread_id] = sum;

    printf("Thread %d done. Result = %e\n", thread_id, sum);

    pthread_exit((void*)thread_id);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Set thread attributes to ensure they are joinable
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Create and start threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        printf("Main: creating thread %d\n", i);
        pthread_create(&threads[i], &attr, thread_function, (void*)&thread_ids[i]);
    }

    // Wait for threads to complete and collect results
    void* status;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &status);
        printf("Main: completed join with thread %d having a status of %d\n", i, (int)status);
    }

    // Calculate the overall result
    double overall_result = 0.0;
    for (int i = 0; i < NUM_THREADS; i++) {
        overall_result += thread_results[i];
    }

    printf("Main: program completed. Overall result = %e. Exiting.\n", overall_result);

    // Clean up thread attributes
    pthread_attr_destroy(&attr);

    return 0;
}
