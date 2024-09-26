//Exercise 2. A thread can get its own thread id by calling pthread_self(), which returns the thread id: pthread_t
//pthread_self();
//Use it as
//pthread_t tid;
//tid = pthread_self();
//Modify the code for hello.c to print out the thread id for both threads. Recompile and run the
//helloexecutable. The new ouput should be similar to
//I am thread 1. Created new thread (4) ...
//Hello from new thread 4 - got 11
//
//Now modify the code so that the main thread passes its own thread id to the new thread it creates. Recompile
//and run the hello executable. The output should be similar to
//I am thread 1. Created new thread (4) ...
//Hello from new thread 4 - got 1


#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    pthread_t tid = pthread_self();
    int main_tid = *(int *)arg;
    
    printf("I am thread %d. Created new thread (%ld)...\n", main_tid, (long)tid);
    printf("Hello from new thread %ld - got %d\n", (long)tid, main_tid);
    
    return NULL;
}

int main() {
    pthread_t thread;
    int main_tid = 1;

    if (pthread_create(&thread, NULL, thread_function, &main_tid) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    printf("I am thread %d. Created new thread (%ld)...\n", main_tid, (long)thread);
    pthread_join(thread, NULL);

    return 0;
}

