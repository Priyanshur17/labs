#include <stdio.h>
 #include <pthread.h> 

void* PrintHello(void* data)
{

int my_data = (int)data; 

pthread_detach(pthread_self());
printf("Hello from new thread - got %d\n", my_data); pthread_exit(NULL); 
 }
int main(int argc, char* argv[])
{
int rc; 
 pthread_t thread_id;
int t = 11; 
 rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t); if(rc) 

{
printf("\n ERROR: return code from pthread_create is %d \n", rc);
exit(1);

}
printf("\n Created new thread (%d) ... \n", thread_id);
pthread_exit(NULL);  }
