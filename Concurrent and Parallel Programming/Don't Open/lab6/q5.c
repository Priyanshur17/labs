#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10 // Define the size of the matrix and vector

void matrixVectorMult(int *A, int *x, int *y, int n)
{
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        y[i] = 0;
        for (int j = 0; j < n; j++)
        {
            y[i] += A[i * n + j] * x[j];
        }
    }
}

int main()
{
    int *A = (int *)malloc(N * N * sizeof(int));
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    // Initialize matrix A and vector x
    for (int i = 0; i < N; i++)
    {
        x[i] = i;
        for (int j = 0; j < N; j++)
        {
            A[i * N + j] = i + j;
        }
    }

    // Perform matrix-vector multiplication
    double start_time = omp_get_wtime(); // Start timer
    matrixVectorMult(A, x, y, N);
    double end_time = omp_get_wtime(); // End timer

    // Print the result (vector y)
    printf("Result (vector y):\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\n ", y[i]);
    }
    printf("\n");

    printf("Computation Time: %.2f seconds", end_time - start_time);

    free(A);
    free(x);
    free(y);

    return 0;
}

// #include <stdio.h>
// #include <omp.h>
// #define N 2500
// #define M 100
// int A[N][N];
// int B[N];
// int C[N];
// int main()
// {
//     int i, j, k;
//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             A[i][j] = i + j;
//         }
//     }
//     for (i = 0; i < N; i++)
//     {
//         B[i] = i;
//     }
// #pragma omp parallel for private(j, k) shared(A, B, C) schedule(staƟc, M)
//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             C[i] += A[i][j] * B[j];
//         }
//     }
//     prinƞ("Result:\n");
//     for (i = 0; i < N; i++)
//     {
//         prinƞ("%d\n", C[i]);
//     }
//     return 0;
// }