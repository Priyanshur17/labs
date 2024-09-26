#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10000000 // Adjust the array size as needed

int main() {
    int* arr = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    int sum = 0;
    double start_time, end_time;
    int num_threads;

    // Initialize the array with values (for demonstration purposes)
    int i;
    for ( i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }

    // Measure computation time with different numbers of threads
    int num_threads;
    for ( num_threads = 2; num_threads <= 8; num_threads += 2) {
        sum = 0;

        start_time = omp_get_wtime(); // Get start time

        #pragma omp parallel num_threads(num_threads)
        {
            int local_sum = 0;

            #pragma omp for
            for (int i = 0; i < ARRAY_SIZE; i++) {
                local_sum += arr[i];
            }

            // Use a critical section to update the shared sum
            #pragma omp critical
            sum += local_sum;
        }

        end_time = omp_get_wtime(); // Get end time

        printf("Number of threads: %d\n", num_threads);
        printf("Sum: %d\n", sum);
        printf("Computation time: %.6f seconds\n", end_time - start_time);
        printf("\n");
    }

    free(arr);

    return 0;
}

