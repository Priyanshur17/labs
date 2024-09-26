#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

void *func(){

	int *a=(int*) malloc(sizeof(int));
	printf("tid  %lu\n",pthread_self());	
	pthread_exit(&a);

}

int main(int argc,char *argv){
	
	pthread_t th;
	if(pthread_create(&th,NULL,&func,NULL)){
		printf("Error occurred while creating the thread");
	}
	else{
		printf("Created a new thread\n");
	
	}
	int *i;
	pthread_join(&th,(void**)&i);
	printf("The value of thread is %d\n",&i);
	return 0;

}
