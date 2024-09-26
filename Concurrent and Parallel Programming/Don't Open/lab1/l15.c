#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int convert(char *s) {
    int num = 0;
    int i = 0;

    while (s[i] != '\0') {
        int a = s[i] - '0';
        num = num * 10 + a;
        i++;
    }

    return num;
}

void *Print(void *data) {
    int *my_data = (int *)data;
    pthread_detach(pthread_self());
    printf("Hello from thread %ld - I was created in iteration %d\n", pthread_self(), *my_data);
    free(data);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        exit(1);
    }

    int n = convert(argv[1]);

    pthread_t t[n];

    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            sleep(1);
        }

        int *a = malloc(sizeof(int));
        if (a == NULL) {
            perror("malloc");
            exit(1);
        }
        *a = i;

        int rc = pthread_create(&t[i], NULL, Print, a);
        if (rc) {
            fprintf(stderr, "pthread_create error: %d\n", rc);
            exit(1);
        }

        printf("I am the main thread %ld, created new thread with %ld in iteration %d\n", pthread_self(), t[i], i);
    }

    // Wait for all threads to finish
    for (int i = 1; i <= n; i++) {
        pthread_join(t[i], NULL);
    }

    printf("Main thread %ld exiting\n", pthread_self());
    pthread_exit(NULL);
}



