#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_SIMULATION_STEPS 5

pthread_barrier_t barrier;

void *simulate_component(void *arg) {
    int component_id = *(int *)arg;

    for (int step = 0; step < NUM_SIMULATION_STEPS; step++) {
        printf("Component %d: Performing simulation step %d\n", component_id, step);
       

        pthread_barrier_wait(&barrier);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, simulate_component, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);

    return 0;
}

