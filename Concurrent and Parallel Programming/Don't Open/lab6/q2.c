#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10000000

int main() {
    int* array = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    int sum = 0;
    double start_time, end_time;

   
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 1;
    }

 
    start_time = omp_get_wtime();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end_time = omp_get_wtime();
    printf("Sequential Sum: %d\n", sum);
    printf("Sequential Time: %f seconds\n", end_time - start_time);


    for (int j = 2; j <= 8; j += 2) {
        sum = 0;
       
        start_time = omp_get_wtime();

        #pragma omp parallel num_threads(j)
        {
        
        int lsum=0;
        int tid=omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int left_index = (ARRAY_SIZE / num_threads)*tid;
        int right_index = (ARRAY_SIZE / num_threads)*(tid+1) -1;
        if(tid==num_threads -1){
        right_index = ARRAY_SIZE-1;
        }
        for (int i = left_index; i <=right_index; i++) {
            lsum += array[i];
        }
        #pragma omp critical 
        {
           sum +=lsum;
        }
        }
        end_time = omp_get_wtime();
        printf("Parallel Sum with %d threads: %d\n", j, sum);
        printf("Parallel Time with %d threads: %f seconds\n", j, end_time - start_time);
    }

    free(array);
    return 0;
}
