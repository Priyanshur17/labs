// Implementation of Boss/Worker Model: Here the idea is to have a single boss thread
// that creates work and several worker threads that process the work. Typically the
// boss thread creates a certain number of workers right away -even before any work
// has arrived. The worker threads form a thread pool and are all programmed to block

// immediately. When the boss thread generates some work, it arranges to have one
// worker thread unblock to handle it. When all workers be busy the boss thread might
// do one of the following by taking request from the user
// 1. Queue up the work to be handled later as soon as a worker is free.
// 2. Create more worker threads.
// 3. Block until a worker is free to take the new work.
// If no work has arrived recently and there are an excessive number of worker threads in
// the thread pool, the boss thread might terminate a few of them to recover resources. In
// any case, since creating and terminate threads is relatively expensive (compared to, say,
// blocking on a mutex) it is generally better to avoid creating a thread for each unit of work
// produced.


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_WORKERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t worker_cond = PTHREAD_COND_INITIALIZER;

int work_queue = 0; // Number of pending work items
int num_workers = 2; // Initial number of worker threads

void* worker_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (work_queue == 0) {
            pthread_cond_wait(&worker_cond, &mutex);
        }

        // Simulate processing work
        work_queue--;
        printf("Worker %lu is processing work. Work queue size: %d\n", pthread_self(), work_queue);
        
        pthread_mutex_unlock(&mutex);

        // Simulate work processing time
        sleep(1);
    }
    pthread_exit(NULL);
}

void create_worker_threads(int num) {
    for (int i = 0; i < num; i++) {
        pthread_t tid;
        pthread_create(&tid, NULL, worker_thread, NULL);
    }
}

int main() {
    pthread_t boss_thread;
    
    create_worker_threads(num_workers);
    
    while (1) {
        char choice;
        printf("\nEnter your choice (1 - Queue work, 2 - Create more workers, 3 - Block until worker available, q - Quit): ");
        scanf(" %c", &choice);
        
        if (choice == '1') {
            pthread_mutex_lock(&mutex);
            work_queue++;
            pthread_cond_signal(&worker_cond);
            pthread_mutex_unlock(&mutex);
        } else if (choice == '2') {
            if (num_workers < MAX_WORKERS) {
                num_workers++;
                create_worker_threads(1);
                printf("Created a new worker. Total workers: %d\n", num_workers);
            } else {
                printf("Maximum number of workers reached.\n");
            }
        } else if (choice == '3') {
            pthread_mutex_lock(&mutex);
            while (work_queue == num_workers) {
                printf("No worker available. Blocking...\n");
                pthread_cond_wait(&worker_cond, &mutex);
            }
            work_queue++;
            pthread_cond_signal(&worker_cond);
            pthread_mutex_unlock(&mutex);
        } else if (choice == 'q' || choice == 'Q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Clean up worker threads (not recommended for production use)
    sleep(1); // Allow some time for worker threads to finish
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&worker_cond);

    return 0;
}
