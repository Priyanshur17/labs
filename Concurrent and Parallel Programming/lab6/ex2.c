#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<unistd.h>

int arr[10000000];

int main(){
	int n=sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++){
		arr[i]=1;
	}
	int globalSum=0;	
	int no_threads;
	double startingTime=omp_get_wtime();
	#pragma omp parallel  num_threads(20)
	{
		int localSum=0;
		int tid=omp_get_thread_num();
		no_threads=omp_get_num_threads();
		int leftIndex=(n/no_threads)*tid;
		int rightIndex=(n/no_threads)*(tid+1)-1;
		if(tid==no_threads-1){
			rightIndex=n-1;
		}
		
		for(int i=leftIndex;i<=rightIndex;i++){
			localSum+=arr[i];
		}
		
		#pragma omp critical
		globalSum+=localSum;		
	}
	double endingTime=omp_get_wtime();
	double timeTaken=endingTime-startingTime;
	printf("The sum of elements of array using %d threads is %d and total time taken is %lf\n",no_threads,globalSum,timeTaken);
	return 0;
}
