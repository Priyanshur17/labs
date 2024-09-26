
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000; 

pthread_mutex_t mutx = PTHREAD_MUTEX_INITIALIZER;

void *deposit(void *arg)
{
    int amt = 50, i;
    for(i=0; i<50; i++)
    {
        pthread_mutex_lock(&mutx); 
        balance = balance + amt;
        pthread_mutex_unlock(&mutx); 
    }
    return NULL;
}

void *withdraw(void *arg)
{
    int amt = 20, i;
    for(i=0; i<20; i++)
    {
        pthread_mutex_lock(&mutx); 
        balance = balance - amt;
        pthread_mutex_unlock(&mutx); 
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int ret;
    ret = pthread_create(&t1, NULL, deposit, NULL);
    if(ret != 0)
    {
        printf("Thread Create Error.\n");
        return 0;
    }

    ret = pthread_create(&t2, NULL, withdraw, NULL);
    if(ret != 0)
    {
        printf("Thread Create Error.\n");
        return 0;
    }

    ret = pthread_join(t1, NULL);
    if(ret != 0)
    {
        printf("Thread Join Error.\n");
        return 0;
    }

    ret = pthread_join(t2, NULL);
    if(ret != 0)
    {
        printf("Thread Join Error.\n");
        return 0;
    }
    printf("Balance is : %d\n", balance);
    return 0;
}
