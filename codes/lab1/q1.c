#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Hello from new thread - got %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t thread;
    int value = 11;

    if (pthread_create(&thread, NULL, thread_function, &value) != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    printf("Created new thread (%ld)...\n", (long)thread);
    pthread_join(thread, NULL);

    return 0;
}
