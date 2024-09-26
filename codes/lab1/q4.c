//The pthread_join()  threads is the equivalent of wait() for processes. A call to
//pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> // Added for exit function

void* PrintHello(void* data) {
    pthread_t tid = (pthread_t)data;
    pthread_join(tid, NULL);
    printf("Hello from new thread %lu - got %d\n", pthread_self(), (int)data);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int rc;
    pthread_t thread_id;
    int tid;
    tid = (int)pthread_self();

    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)tid);
    if (rc) {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }

    sleep(1);
    printf("\n Created new thread (%lu) ... \n", thread_id);

    pthread_exit(NULL); // This line ensures that the main thread exits gracefully.
}

