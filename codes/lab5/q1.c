//Exercise 1: OpenMP Hello-world Program (Implement the first OpenMP program)
//You are expected to complete the basic understanding of OpenMP environment, i.e., how to
//compile an OpenMP program, how to set the number of OpenMP threads and retrieve the
//thread ID number at runtime.
//? Find out the default number of threads of your system.
//? Observer the behaviour of the threads. Is there any possibility that two threads can
//interleave the printing of “hello world”.
//? Write a program to print Thread id and number of threads using different clauses i.e
//omp barrier, thread private, two parallel regions, omp single. Avoid race condition.

#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads, thread_id;

    // Get the default number of threads
    #pragma omp parallel
    {
        num_threads = omp_get_num_threads();
        thread_id = omp_get_thread_num();
        printf("Hello from thread %d of %d\n", thread_id, num_threads);
    }

    // By default, threads can interleave printing
    printf("Threads can interleave the printing of 'Hello, World!'\n");

    // Using OpenMP directives to control synchronization
    #pragma omp parallel num_threads(4) private(thread_id)
    {
        num_threads = omp_get_num_threads();
        thread_id = omp_get_thread_num();

        // Use omp barrier to synchronize threads
        #pragma omp barrier

        // Avoid race condition by printing thread ID and number of threads safely
        #pragma omp critical
        {
            printf("Thread ID: %d, Number of Threads: %d\n", thread_id, num_threads);
        }

        // Use omp single to execute the following block by a single thread
        #pragma omp single
        {
            printf("This block is executed by a single thread.\n");
        }
    }

    return 0;
}

