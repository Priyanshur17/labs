#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



typedef struct {
    int *array;
    int start;
    int end;
} ThreadArgs;

void merge(int array[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void *mergeSort(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *)args;
    int start = threadArgs->start;
    int end = threadArgs->end;
    int *array = threadArgs->array;

    if (start < end) {
        int mid = start + (end - start) / 2;

        ThreadArgs leftArgs = { array, start, mid };
        ThreadArgs rightArgs = { array, mid + 1, end };

        pthread_t leftThread, rightThread;
        pthread_create(&leftThread, NULL, mergeSort, (void *)&leftArgs);
        pthread_create(&rightThread, NULL, mergeSort, (void *)&rightArgs);

        pthread_join(leftThread, NULL);
        pthread_join(rightThread, NULL);

        merge(array, start, mid, end);
    }

    pthread_exit(NULL);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    ThreadArgs initialArgs = { array, 0, size - 1 };
 
    pthread_t initialThread;
    pthread_create(&initialThread, NULL, mergeSort, (void *)&initialArgs);
    pthread_join(initialThread, NULL);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}

