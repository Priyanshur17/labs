#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        #pragma omp task
        quicksort(arr, low, pivotIndex - 1);

        #pragma omp task
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

   
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    #pragma omp parallel
    {
        #pragma omp single nowait
        quicksort(arr, 0, size - 1);
    }

    // Output sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


