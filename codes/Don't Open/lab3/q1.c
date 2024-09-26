#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Global variables
char *s1, *s2;
int n1, n2;
int totalMatches = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *searchSubstrings(void *arg) {
    int thread_id = *(int *)arg;
    int localMatches = 0;
    int chunkSize = n1 / 2;
    int start = thread_id * chunkSize;
    int end = start + chunkSize;

    for (int i = start; i < end - n2 + 1; i++) {
        if (strncmp(s1 + i, s2, n2) == 0) {
            localMatches++;
        }
    }

    pthread_mutex_lock(&mutex);
    totalMatches += localMatches;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }


    size_t n = 0;
    ssize_t n1_read = getline(&s1, &n, file);
    ssize_t n2_read = getline(&s2, &n, file);

    if (n1_read == -1 || n2_read == -1) {
        perror("Error reading strings");
        return 1;
    }

    fclose(file);

    n1 = strlen(s1);
    n2 = strlen(s2) - 1; 

    pthread_t threads[2];
    int thread_ids[2] = {0, 1};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, searchSubstrings, &thread_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of matched substrings: %d\n", totalMatches);

    free(s1);
    free(s2);

    return 0;
}

