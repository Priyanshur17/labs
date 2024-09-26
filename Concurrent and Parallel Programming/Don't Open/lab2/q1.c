#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* PrintHello(void* data){
	
	int my_data = *(int*)data;
	
	for(int i=0;i<5;i++){
	printf("Hello from new thread - got %d\n", my_data); }
	pthread_exit(NULL); 

}

int main(int argc, char* argv[]){

	pthread_t th[10];
	int arr[10] ={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++){
	int rc;
	rc=pthread_create(&th[i],NULL,PrintHello,&arr[i]);
        if(rc){
		printf("\n ERROR: return code from pthread_create is %d \n", rc);
		exit(1);
	}
	}
	for(int j=0;j<10;j++){
	pthread_join(th[j],NULL);
	}
	
}
