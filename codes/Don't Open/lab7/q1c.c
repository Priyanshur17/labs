#include <omp.h>
#include <stdio.h>

#define MATRIX_SIZE 100
#define NUM_THREADS 8

int main() {

    int i, j, k;
    int cnt =0;
    omp_set_num_threads(NUM_THREADS);


    #pragma omp parallel for 
    for (i = 0; i < MATRIX_SIZE; i++) 
    #pragma omp parallel for 
        for (j = 0; j < MATRIX_SIZE; j++) {
  
            for (k = 0; k < MATRIX_SIZE; k++) {
         
                if(omp_get_thread_num()== 0 )
                 cnt++;
            }
        }
    

    printf("Resulting matrix C: %d\n", cnt);
    return 0;
}

