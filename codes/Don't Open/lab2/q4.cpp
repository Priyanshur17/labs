#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 100
#define MAX_THREADS 5

struct ThreadSafeString {
    char data[MAX_STRING_LENGTH];
    pthread_mutex_t mtx;
};

void initThreadSafeString(struct ThreadSafeString *tsString) {
    memset(tsString->data, 0, sizeof(tsString->data));
    pthread_mutex_init(&tsString->mtx, NULL);
}

void append(struct ThreadSafeString *tsString, const char *str) {
    pthread_mutex_lock(&tsString->mtx);
    strncat(tsString->data, str, MAX_STRING_LENGTH - strlen(tsString->data) - 1);
    pthread_mutex_unlock(&tsString->mtx);
}

void getData(struct ThreadSafeString *tsString, char *result, size_t resultSize) {
    pthread_mutex_lock(&tsString->mtx);
    strncpy(result, tsString->data, resultSize - 1);
    pthread_mutex_unlock(&tsString->mtx);
}

struct ThreadData {
    struct ThreadSafeString *tsString;
    int threadNum;
};

void *appendThread(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    char str[MAX_STRING_LENGTH];
    snprintf(str, MAX_STRING_LENGTH, "Thread %d ", data->threadNum);
    append(data->tsString, str);
    return NULL;
}

int main() {
    struct ThreadSafeString tsString;
    initThreadSafeString(&tsString);

    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; ++i) {
        threadData[i].tsString = &tsString;
        threadData[i].threadNum = i;
        pthread_create(&threads[i], NULL, appendThread, &threadData[i]);
    }

    for (int i = 0; i < MAX_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    char result[MAX_STRING_LENGTH * MAX_THREADS];
    getData(&tsString, result, sizeof(result));

    printf("Final string: %s\n", result);

    pthread_mutex_destroy(&tsString.mtx);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 256

// Define a structure for the thread-safe string
typedef struct {
    char data[MAX_STRING_LENGTH];
    pthread_mutex_t mutex;
} ThreadSafeString;

// Function to initialize a thread-safe string
void initThreadSafeString(ThreadSafeString *str) {
    memset(str->data, 0, MAX_STRING_LENGTH);
    pthread_mutex_init(&str->mutex, NULL);
}

// Function to set the value of the thread-safe string
void setThreadSafeString(ThreadSafeString *str, const char *value) {
    pthread_mutex_lock(&str->mutex);
    strncpy(str->data, value, MAX_STRING_LENGTH - 1);
    pthread_mutex_unlock(&str->mutex);
}

// Function to get the value of the thread-safe string
const char *getThreadSafeString(ThreadSafeString *str) {
    const char *result;
    pthread_mutex_lock(&str->mutex);
    result = str->data;
    pthread_mutex_unlock(&str->mutex);
    return result;
}

// Function executed by threads
void *threadFunction(void *arg) {
    ThreadSafeString *sharedString = (ThreadSafeString *)arg;

    // Modify the shared string safely
    setThreadSafeString(sharedString, "Hello from thread!");

    // Print the modified string
    printf("Thread: %s\n", getThreadSafeString(sharedString));

    return NULL;
}

int main() {
    pthread_t threads[3];
    ThreadSafeString myString;

    initThreadSafeString(&myString);

    // Create multiple threads to work with the shared string
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, threadFunction, &myString) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Print the final value of the shared string
    printf("Main: %s\n", getThreadSafeString(&myString));

    return 0;
}
