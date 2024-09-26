//Exercise 6 . Write a program to return a value from the thread using Join function call.
#include <stdio.h>
#include <pthread.h>

void* ThreadFunction(void* arg) {
    int* value = (int*)arg;
    *value = 42; // Set a value to be returned
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int return_value = 0;

    if (pthread_create(&thread, NULL, ThreadFunction, &return_value) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    printf("The value returned by the thread is: %d\n", return_value);

    return 0;
}

