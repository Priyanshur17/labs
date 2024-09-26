#include <stdio.h>
#include<omp.h>
#define N 100

int main(){
	int a[N][N],b[N][N],c[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j]=2;
			b[i][j]=2;
			c[i][j]=0;
		}
	}
	
	int cnt1=0;
	#pragma omp parallel for num_threads(8)
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){		
			for(int k=0;k<N;k++){
			int tid=omp_get_thread_num();
				if(tid==0){
					cnt1++;
				}
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	printf("Operations performed by innermost loop when only outermost loop is parallelized are %d",cnt1);
	return 0;
	
	


}
