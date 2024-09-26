//Exercise 5. Write a program hellomany.c that will create a number N of threads specified in the command
//line, each of which prints out a hello message and its own thread ID. To see how the execution of the threads
//interleaves, make the main thread sleep for 1 second for every 4 or 5 threads it creates. The output of your code
//should be similar to:
//I am thread 1. Created new thread (4) in iteration 0... Hello from thread 4 - I
//was created in iteration 0 I am thread 1. Created new thread (6) in iteration 1...
//I am thread 1. Created new thread (7) in iteration 2... I am thread 1. Created new
//thread (8) in iteration 3... I am thread 1. Created new thread (9) in iteration
//4... I am thread 1. Created new thread (10) in iteration 5... Hello from thread 6
//- I was created in iteration 1 Hello from thread 7 - I was created in iteration 2
//Hello from thread 8 - I was created in iteration 3 Hello from thread 9 - I was
//created in iteration 4 Hello from thread 10 - I was created in iteration 5 I am
//thread 1. Created new thread (11) in iteration 6... I am thread 1. Created new
//thread (12) in iteration 7... Hello from thread 11 - I was created in iteration 6
//Hello from thread 12 - I was created in iteration 7













#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_THREADS 10 // Maximum number of threads

void* ThreadFunction(void* arg) {
    int thread_id = *(int*)arg;
    printf("Hello from thread %d - I was created in iteration %d\n", thread_id, thread_id - 4);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Number of threads should be between 1 and %d\n", MAX_THREADS);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 4; i < num_threads + 4; i++) {
        thread_ids[i - 4] = i;
        if (i % 4 == 0 || i % 5 == 0) {
            sleep(1);
            printf("I am thread 1. Created new thread (%d) in iteration %d...\n", i, i - 4);
        }
        pthread_create(&threads[i - 4], NULL, ThreadFunction, &thread_ids[i - 4]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

