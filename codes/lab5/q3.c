#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#define MAX_SIZE 5000
#define MIN_SIZE 500
void main()
{
    int buff = 6000;
    #pragma omp parallel num_threads(2)
    {
    #pragma omp barrier
        if (omp_get_thread_num() == 0)
        {
            // #pragma omp for
            for (int i = 0; i < 10; i++)
            {
                while (buff >= MAX_SIZE)
                    continue;
                #pragma omp critical
                {
                    buff += 500, printf("Producer here, Buffer: %d\n", buff);
                }
            }
        }
        else
        {
            // #pragma omp for
            for (int i = 0; i < 10; i++)
            {
                while (buff <= MIN_SIZE)
                    continue;

                #pragma omp critical
                {
                    buff -= 500, printf("Consumer here, Buffer: %d\n", buff);
                }
            }
        }
    }
}
