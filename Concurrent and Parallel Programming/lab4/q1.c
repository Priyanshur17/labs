// Write a program where 2 threads communicate using a single global variable “balance”
// and initialized to 1000..Thread 1 deposits amount = 50 for for 50 times and prints the
// balance amount and thread 2 withdrawals amount=20 for 20 times and prints the final
// balance .Execution of thread 1 and thread 2 should not interleave.

#include <stdio.h>
#include <pthread.h>

#define NUM_DEPOSITS 50
#define NUM_WITHDRAWALS 20

int balance = 1000;
pthread_mutex_t mutex;

void* deposit(void* arg) {
    for (int i = 0; i < NUM_DEPOSITS; i++) {
        pthread_mutex_lock(&mutex);
        balance += 50;
        printf("Thread 1 deposited $50. New balance: $%d\n", balance);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* withdraw(void* arg) {
    for (int i = 0; i < NUM_WITHDRAWALS; i++) {
        pthread_mutex_lock(&mutex);
        balance -= 20;
        printf("Thread 2 withdrew $20. New balance: $%d\n", balance);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&thread1, NULL, deposit, NULL);
    pthread_create(&thread2, NULL, withdraw, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Clean up the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
