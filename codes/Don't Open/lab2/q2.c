#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<math.h>


void* squareRoot(void* data){
	
	
	
	double  *arr = (double*)malloc(99 * sizeof(double));
	for(int i=0;i<100;i++){
	arr[i] = sqrt(i);
	}
	return (void *)arr;

}

int main(int argc, char* argv[]){

	int rc;
	pthread_t tid;
	
	rc=pthread_create(&tid, NULL, squareRoot, NULL); 
	if(rc){
		printf("\n ERROR: return code from pthread_create is %d \n", rc);
		exit(1);
	}
	else
	printf("\n Created new thread (%lu) ... \n", tid);
	
	double* res;
	 if (pthread_join(tid, (void**) &res) != 0) {
        return 2;
    }
    
    for(int i=0;i<100;i++){
    printf("the square root of %d is : %lf \n " ,i,res[i]);
	
}

}
