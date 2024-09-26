#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *Print(void *data){
    
    int my_data = (int) data;
     pthread_t tid;
     tid = pthread_self();
    pthread_detach(pthread_self());
    printf("hello from new thread %d - got %d\n", tid, my_data);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
      
      int rc;
      pthread_t thread_id;
       
      pthread_t tid;
      tid = pthread_self();
      
      int t = 11;
      
      rc = pthread_create(&thread_id,NULL,Print,(void *)t);
      if(rc){
         
         printf("\n error : return code from pthread_create is %d \n",rc);
         exit(1);
      }
     
      
      printf("\nI am thread %d. created new thread %d ....\n",tid,thread_id);
      pthread_exit(NULL);

}


