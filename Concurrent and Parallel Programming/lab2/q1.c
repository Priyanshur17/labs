//1. Write a program that creates 10 threads. Have each thread execute the same function and pass each thread a
//unique number. Each thread should print “Hello, World (thread n)” five times where ‘n’ is replaced by the
//thread’s number. Use an array of pthread t objects to hold the various thread IDs. Be sure the program doesn’t
//terminate until all the threads are complete.
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8
#define ITERATIONS 3
int count=0;
void* PrintHello(void* thread_number) {
    int num = *(int*)thread_number;
    int i;
    for (i = 0; i < ITERATIONS; i++) {
        printf("Hello, World (thread %d)\n", num);
        sleep(1);
        count++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Create 10 threads and pass a unique number to each thread
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, PrintHello, &thread_args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to complete
    
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
    }

    printf("All threads have completed.\n %d",count);

    return 0;
}

