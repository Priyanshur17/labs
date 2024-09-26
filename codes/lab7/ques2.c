#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void quicksort(int arr[], int left, int right);

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
           
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

 
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

void parallel_quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);

        #pragma omp task
        {
            parallel_quicksort(arr, left, pivot_index - 1);
        }
        #pragma omp task
        {
            parallel_quicksort(arr, pivot_index + 1, right);
        }
    }
}

int main() {
    int arr[] = {12, 23, 15, 36, 17,90, 11, 55, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    #pragma omp parallel
    {
        #pragma omp single nowait
        parallel_quicksort(arr, 0, n - 1);
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
