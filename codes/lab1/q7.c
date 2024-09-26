#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int arr[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 };
int j;
void* arrsum(void* arg) {
    int index = *(int*)arg;
    int *lsum;
    lsum= (int*)malloc(sizeof(int));
    *lsum=0;
    for (j = 0; j < 5; j++) {
        *lsum += arr[index + j];
    }
    printf("\nLocal sum: %d\n", *lsum);
      // *(int*)arg = lsum;
       return lsum;       
}
int main(int argc, char* argv[]) {
    pthread_t th[3];
    int i;
    for (i = 0; i < 3; i++) {
        int* a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &arrsum, a) != 0) {
            perror("Failed to create thread");
        }
    }
    int gSum = 0;
    int* r;
    for (i = 0; i < 3; i++) {
       // int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        printf("\n The value received in join is: %d\n", *r);
        gSum += *r;
        free(r);
    }
    printf("\nFinal Global sum: %d\n", gSum);
    return 0;
}
