#include <stdio.h>
#include <omp.h>

#define N 10// Adjust the size of the matrix

int main() {
    int matrix[N][N];
    int vector[N];
    int result[N];

    // Initialize the matrix and vector
    for (int i = 0; i < N; i++) {
        vector[i] = i + 1; // Initialize the vector with values 1 to N
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i * j; // Initialize the matrix with values i*j
        }
    }

    // Perform matrix-vector multiplication using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        result[i] = 0; // Initialize the result vector
        for (int j = 0; j < N; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    // Print the result vector
    printf("Result vector:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
