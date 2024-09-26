#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
pthread_mutex_t mutexAmmount;
pthread_cond_t c1;
int amount = 1000;
int i;
void* deposit(void* arg) {
    for(i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutexAmmount);
        amount += 15;
        printf("Total amount... %d\n", amount);
        pthread_mutex_unlock(&mutexAmmount);
        pthread_cond_signal(&c1);
        sleep(1); 
    }
}
void* withdrawl(void* arg) {
  for(int i=0;i<3;i++){
    pthread_mutex_lock(&mutexAmmount);
      while(amount<1000)
    {
    printf("Insuffient amount for withdrawl, just wait \n");
    pthread_cond_wait(&c1, &mutexAmmount);
      
	} 
     amount -= 40;
    printf("Got cash. Now left: %d\n", amount);
    pthread_mutex_unlock(&mutexAmmount);
    }
}
int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    pthread_mutex_init(&mutexAmmount, NULL);
    pthread_cond_init(&c1, NULL);
    for(i = 0; i < 2; i++) {
        if (i == 1) {
            if (pthread_create(&th[i], NULL, &deposit, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &withdrawl, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexAmmount);
    pthread_cond_destroy(&c1);
    return 0;
}
