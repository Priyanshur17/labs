#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void* fun1(void* arg) {
   // sleep(1);
    int index = *(int*)arg;
    printf("%d ", arr[index]);
    free(arg);
}

int main(int argc, char* argv[]) {
    pthread_t th[10];
    int i,j;
    
    for (i = 0; i < 10; i++) {
          int *a = malloc(sizeof(int));
          *a = i;
        if (pthread_create(&th[i], NULL, &fun1, a) != 0) {
            perror("Failed to created thread");
        }
    }
    for (j = 0; j< 10;j++) {
        if (pthread_join(th[j], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    
    return 0;
}

