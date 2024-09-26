#include<stdio.h>
 #include<omp.h>

 int main ( int argc , char * argv []) {
    int max ;  
    sscanf ( argv [1] , " %d " , & max ) ;
    int tasks ; 
    sscanf ( argv [2] , " %d " , & tasks ) ;
   if ( max % tasks != 0) return 1;
   int sum = 0;
 # pragma omp parallel
  {
 # pragma omp single
   for ( int t = 0; t < tasks ; t ++) {
 # pragma omp task
 {
   int local_sum = 0;
   int lo = ( max / tasks ) * ( t + 0) + 1;
   int hi = ( max / tasks ) * ( t + 1) + 0;
   
 for ( int i = lo ; i <= hi ; i ++)
  local_sum = local_sum + i ;
  # pragma omp atomic
  sum = sum + local_sum ;
  }
  }
 }
 printf ( " %d \n " , sum ) ;
 return 0;
  }
