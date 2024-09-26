//Demonstration of Race Condition in producer and consumer problem using thread
//implementation.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
pthread_mutex_t mutexFuel;
int fuel = 0;
int i;
void* tank_filling(void* arg) {
    for(i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        sleep(1); 
    }
}
void* car_filling(void* arg) {
    pthread_mutex_lock(&mutexFuel);
 //   fuel -= 40;
 //   printf("Got fuel. Now left: %d \n", fuel);
     if(fuel>=40)
    {
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
	} else
	   printf("\n No fuel in tank...\n");  
    pthread_mutex_unlock(&mutexFuel);
}
int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    pthread_mutex_init(&mutexFuel, NULL);
    for(i = 0; i < 2; i++) {
        if (i == 0) {
            if (pthread_create(&th[i], NULL, &tank_filling, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &car_filling, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}
