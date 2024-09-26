//2. Write a program that computes the square roots of the integers from 0 to 99 in a separate thread and returns an
//array of doubles containing the results. In the meantime the main thread should display a short message to the
//user and then display the results of the computation when they are ready.

#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NUM_INTEGERS 100

// Structure to hold thread-specific data
typedef struct {
    int start;
    int end;
    double* results;
} ThreadArgs;

void* ComputeSquares(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int i;
    for ( i = args->start; i < args->end; i++) {
        args->results[i] = sqrt((double)i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    double results[NUM_INTEGERS];

    // Create a structure to hold thread-specific data
    ThreadArgs args;
    args.start = 0;
    args.end = NUM_INTEGERS;
    args.results = results;

    // Create a thread to compute square roots
    if (pthread_create(&thread, NULL, ComputeSquares, &args) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Display a short message
    printf("Calculating square roots. Please wait...\n");

    // Wait for the thread to complete
    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    // Display the results
    int i;
    for ( i = 0; i < NUM_INTEGERS; i++) {
        printf("sqrt(%d) = %.2f\n", i, results[i]);
        sleep(1);
		    }

    return 0;
}

