#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
pthread_mutex_t mutexFuel;
pthread_cond_t c1;
int fuel = 0;
int i;
void* tank_filling(void* arg) {
    for(i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        if(fuel>=40)pthread_cond_signal(&c1);
        sleep(1); 
    }
}
void* car_filling(void* arg) {
    pthread_mutex_lock(&mutexFuel);
      while(fuel<40)
    {
    printf("Insuffient fuel, just wait \n");
    pthread_cond_wait(&c1, &mutexFuel);
      // three operations are involved in cond:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
	} 
     fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}
int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&c1, NULL);
    for(i = 0; i < 2; i++) {
        if (i == 1) {
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
    pthread_cond_destroy(&c1);
    return 0;
}
