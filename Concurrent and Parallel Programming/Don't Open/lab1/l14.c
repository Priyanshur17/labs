#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* Print(void *data){
    
    pthread_t tid = (pthread_t)data;
    pthread_join(tid, NULL);
    //pthread_detach(pthread_self());
    printf("hello from new thread %d - got %d\n", pthread_self(), data);
   // pthread_exit(NULL);
}

int main(int argc, char *argv[]){
      
      int rc;
      pthread_t thread_id;
       
      pthread_t  tid;
      tid = pthread_self();
      
      //printf("\nI am thread %d. created new thread %d ....\n",tid,thread_id);
      //int t = 11;
      
      rc = pthread_create(&thread_id,NULL,Print,(void *)tid);
      if(rc){
         
         printf("\n error : return code from pthread_create is %d \n",rc);
         exit(1);
      }
     
      sleep(1);
      printf("\ncreated new thread %d ....\n",thread_id);
      
      pthread_exit(NULL);

}

