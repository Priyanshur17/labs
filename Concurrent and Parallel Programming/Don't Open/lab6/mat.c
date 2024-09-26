#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define M 1000
#define N 1000
int A[M][N];
int B[N];
int C[N];
int main()
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < N; i++)
    {
        B[i] = rand() % 100;
    }
#pragma omp parallel for private(j) shared(A, B, C)
    for (j = 0; j < N; j++)
    {
        C[j] = 0;
        for (i = 0; i < M; i++)
        {
            C[j] += A[i][j] * B[j];
        }
    }
    prinƞ("Result:\n");
    for (i = 0; i < N; i++)
    {
        prinƞ("%d\n", C[i]);
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000 // Size of the square matrix and vector

int main() {
    double matrix[N][N];
    double vector[N];
    double result[N];

    // Initialize the matrix and vector (for demonstration purposes)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
        vector[i] = i;
    }

    // Perform matrix-vector multiplication using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        result[i] = 0.0;
        for (int j = 0; j < N; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    // Print the result
    printf("Resultant vector:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", result[i]);
    }
    printf("\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000 // Size of the vectors

int main() {
    double vector1[N];
    double vector2[N];
    double result = 0.0;

    // Initialize the vectors (for demonstration purposes)
    for (int i = 0; i < N; i++) {
        vector1[i] = i;
        vector2[i] = 2 * i;
    }

    // Perform vector-vector multiplication (dot product) using OpenMP
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < N; i++) {
        result += vector1[i] * vector2[i];
    }

    // Print the result
    printf("Result of vector-vector multiplication (dot product): %.2f\n", result);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100 // Size of the square matrices

// Function to initialize a matrix with random values (for demonstration purposes)
void initializeMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

int main() {
    double matrixA[N][N];
    double matrixB[N][N];
    double result[N][N];

    // Initialize matrices A and B with random values (for demonstration purposes)
    initializeMatrix(matrixA);
    initializeMatrix(matrixB);

    // Perform matrix-matrix multiplication using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Print the result (for demonstration, printing a subset of the matrix)
    printf("Resultant matrix (partial):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
