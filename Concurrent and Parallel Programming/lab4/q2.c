// Write a program where 2 threads operate on a global variable “account” initialized to
// 1000. There is a deposit function which deposits a given amount in this “account”: int
// deposit(int amount)
// There is a withdrawal function which withdraws a given amount from the “account”:

// int withdrawal(int amount)

// However there is a condition: withdrawal function should block the calling thread when
// the amount in the “account” is less than 1000, i.e. you can’t withdraw if the “account”
// value is less than 1000. Threads calling the deposit function should indicate to the
// withdrawing threads when the amount is greater than 1000.

#include <stdio.h>
#include <pthread.h>

int account = 1000;
pthread_mutex_t mutex;
pthread_cond_t balance_condition;

int deposit(int amount) {
    pthread_mutex_lock(&mutex);
    account += amount;
    int new_balance = account;
    
    // Signal the withdrawing thread if the balance is now greater than 1000
    if (new_balance > 1000) {
        pthread_cond_signal(&balance_condition);
    }
    
    pthread_mutex_unlock(&mutex);
    return new_balance;
}

int withdrawal(int amount) {
    pthread_mutex_lock(&mutex);
    
    // Wait until the balance is greater than or equal to 1000
    while (account < 1000) {
        pthread_cond_wait(&balance_condition, &mutex);
    }
    
    if (amount <= account) {
        account -= amount;
    } else {
        printf("Insufficient funds!\n");
    }
    int new_balance = account;
    
    pthread_mutex_unlock(&mutex);
    return new_balance;
}

void* deposit_thread(void* arg) {
    int amount = *(int*)arg;
    int new_balance = deposit(amount);
    printf("Deposited $%d. New balance: $%d\n", amount, new_balance);
    pthread_exit(NULL);
}

void* withdrawal_thread(void* arg) {
    int amount = *(int*)arg;
    int new_balance = withdrawal(amount);
    if (new_balance != -1) {
        printf("Withdrawn $%d. New balance: $%d\n", amount, new_balance);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&balance_condition, NULL);

    int deposit_amount = 200;
    int withdrawal_amount = 300;

    // Create threads
    pthread_create(&thread1, NULL, deposit_thread, &deposit_amount);
    pthread_create(&thread2, NULL, withdrawal_thread, &withdrawal_amount);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Clean up the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&balance_condition);

    return 0;
}
