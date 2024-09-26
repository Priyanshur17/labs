//Exercise 3. There are several ways for threads to terminate. One way to safely terminate is to call the
//pthread_exit routine (the equivalent of exit for processeas). In this exercise, modify the your hello.cprogram as
//follows. In the PrintHello routine, add a line before the printf call sleep(1);. This should be the first line of the
//function. In the main function, comment out the last statement line which contains the pthread_exit call.
//Recompile and run the hello executable.
//What happens? Why?
//Now, put the pthread_exit call back in the main program, but remove it from the PrintHello routine. Also
//add the sleep call to the main routine, just before the second printf call, and remove it from the
//PrintHelloroutine. Recompile and run the hello executable.
//What happens? Why?
//It is necessary to use pthread_exit at the end of the main program. Otherwise, when it exits, all running
//threads will be killed.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

void *PrintHello(void *arg) {
    sleep(1); // Sleep added before printf
    printf("Hello from new thread\n");
    return NULL;
}

int main() {
    pthread_t thread;

    if (pthread_create(&thread, NULL, PrintHello, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    printf("I am the main thread\n");
    // Commenting out pthread_exit
    // pthread_exit(NULL);

    return 0;
}

