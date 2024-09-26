#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	#pragma omp parallel num_threads(10)//for setting the number of threads explicitly
	{
		printf("Hello world from thread with no %d\n",omp_get_thread_num());
		#pragma omp single
		{
			int no_threads=omp_get_num_threads();//to get the no of threads in the system 
			sleep(1); 
			printf("The number of threads is %d\n",no_threads);//default no of threads =20
		}
	}
	printf("\nUsing barrier\n");
	#pragma omp parallel num_threads(10)
	{
		int no_threads=omp_get_num_threads();
		#pragma omp barrier
		printf("Hello world from thread with no %d\n",omp_get_thread_num());		
	}
	
	int no_threads=omp_get_num_threads();
	int thread_num=omp_get_thread_num();
	printf("\nUsing private\n");
	#pragma omp parallel private(no_threads,thread_num) num_threads(10)
	{
		no_threads=omp_get_num_threads();
		thread_num=omp_get_thread_num();
		printf("Hello world from thread with no %d\n",thread_num);		
	}
	
	return 0;
}
