#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    int thread_id, num_threads;
    #pragma omp parallel private(thread_id, num_threads)
    {
        thread_id = omp_get_thread_num();
        num_threads = omp_get_num_threads();

        #pragma omp barrier

        printf("Thread %d of %d: Hello, world! (Using OMP BARRIER)\n", thread_id, num_threads);
    }

    #pragma omp parallel private(thread_id, num_threads)
    {
        thread_id = omp_get_thread_num();
        num_threads = omp_get_num_threads();

        printf("Thread %d of %d: Hello, world! (Using THREAD PRIVATE)\n", thread_id, num_threads);
    }

    return 0;
}

