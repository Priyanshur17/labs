#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

void *PrintHello(void *arg) {
    sleep(1); // Sleep removed from here
    printf("Hello from new thread\n");
    return NULL;
}

int main() {
    pthread_t thread;

    if (pthread_create(&thread, NULL, PrintHello, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    printf("I am the main thread\n");
    pthread_exit(NULL); // pthread_exit added

    return 0;
}

