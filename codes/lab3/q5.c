#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
pthread_barrier_t barrier;
void* fun1(void* args) {
 //   while (1) {
        printf("Barrier: Let the other threads come...\n");
     //   sleep(1);
        pthread_barrier_wait(&barrier);
        printf("We passed the barrier\n");
 //       sleep(2);
 //   }
}
int main(int argc, char *argv[]) {
	pthread_t th[2];
	int i;
    pthread_barrier_init(&barrier, NULL, 2);
	for (i = 0; i < 2; i++) {
		if (pthread_create(&th[i], NULL, &fun1, NULL) != 0) {
			perror("Failed to create thread");
		}
	}
	for (i = 0; i < 2; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}
    pthread_barrier_destroy(&barrier);
	return 0;
}
