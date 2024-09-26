//3. WAP that takes an array and its size as arguments. Later, try to use Merge sort to sort the array elements. As, in
//Merge sort, input array is divided into two halves, use two different threads to sort the two sub-arrays,
//recursively. Every thread would create two new threads, and would wait for them to complete. At the end,
//every thread would combine the sorted result of its child threads.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void* MergeSort(void* arg) {
    int* arr = (int*)arg;

    if (arr == NULL) {
        pthread_exit(NULL);
    }

    if (ARRAY_SIZE <= 1) {
        pthread_exit(NULL); // Nothing to sort
    }

    int mid = ARRAY_SIZE / 2;
    int left[mid];
    int right[ARRAY_SIZE - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < ARRAY_SIZE; i++) {
        right[i - mid] = arr[i];
    }

    pthread_t left_thread, right_thread;

    pthread_create(&left_thread, NULL, MergeSort, left);
    pthread_create(&right_thread, NULL, MergeSort, right);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    merge(arr, left, right, mid, ARRAY_SIZE - mid);

    pthread_exit(NULL);
}

int main() {
    int arr[ARRAY_SIZE] = {7, 3, 9, 2, 6, 1, 8, 5, 4, 0};

    printf("Original Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_t sort_thread;

    pthread_create(&sort_thread, NULL, MergeSort, arr);
    pthread_join(sort_thread, NULL);

    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

