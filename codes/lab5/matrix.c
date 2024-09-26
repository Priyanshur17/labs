#include <stdio.h>
#include <omp.h>

#define N 100
 
int A[N][N];
int x[N];
int y[N]={0};

int main(int argv,char* argc[])
{
    for(int i=0;i<N;i++)
    { 
        x[i]=i;
        for(int j=0;j<N;j++)
        {
            A[i][j]=i+j;
        }
    }

    #pragma omp parallel for schedule(dynamic,200)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                y[j]+=A[i][j]*x[j];
            }
        }
    }

    printf("OUTPUT: \n");
    for(int i=0;i<N;i++)
    {
        printf("%d\n",x[i]);
    }
}
