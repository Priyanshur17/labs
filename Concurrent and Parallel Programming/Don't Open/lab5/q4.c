// #include <stdio.h>
// #include <pthread.h>

// #define NUM_WORKERS 5

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// int task_available = 0;

// void *worker_function(void *arg) {
//     int worker_id = *((int *)arg);

//     while (1) {
//         pthread_mutex_lock(&mutex);
//         while (!task_available) {
//             pthread_cond_wait(&cond, &mutex);
//         }

//         printf("Worker %d processing task...\n", worker_id);

//         task_available = 0;
//         pthread_cond_signal(&cond);
//         pthread_mutex_unlock(&mutex);
//     }

//     return NULL;
// }

// int main() {
//     pthread_t workers[NUM_WORKERS];
//     int worker_ids[NUM_WORKERS];

//     for (int i = 0; i < NUM_WORKERS; ++i) {
//         worker_ids[i] = i;
//         pthread_create(&workers[i], NULL, worker_function, &worker_ids[i]);
//     }

//     while (1) {

//         pthread_mutex_lock(&mutex);
//         while (task_available) {
//             pthread_cond_wait(&cond, &mutex);
//         }

//         task_available = 1;
//         pthread_cond_signal(&cond);
//         pthread_mutex_unlock(&mutex);

//     }

//     for (int i = 0; i < NUM_WORKERS; ++i) {
//         pthread_cancel(workers[i]);
//         pthread_join(workers[i], NULL);
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_THREADS 100
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int work_queue[MAX_THREADS];
int num_workers = 0;
int num_work_items = 0;
int next_worker = 0;
void *worker(void *arg)
{
    int worker_id = (int)arg;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (num_work_items == 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        int work_item = work_queue[num_work_items - 1];
        num_work_items--;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        prinƞ("Worker %d processing work item %d\n", worker_id, work_item);
    }
}
void *boss(void *arg)
{
    while (1)
    {
        int command;
        prinƞ("Enter command (1: queue up work, 2: create more workers, 3: block unƟl worker is free): ");
        scanf("%d", &command);
        pthread_mutex_lock(&mutex);
        switch (command)
        {
        case 1:
            if (num_workers == 0)
            {
                prinƞ("No workers available to handle work item\n");
            }
            else
            {
                int work_item;
                prinƞ("Enter work item: ");
                scanf("%d", &work_item);
                work_queue[num_work_items] = work_item;
                num_work_items++;
                pthread_cond_signal(&cond);
            }
            break;
        case 2:
            if (num_workers == MAX_THREADS)
            {
                prinƞ("Maximum number of workers reached\n");
            }
            else
            {
                int worker_id = num_workers;
                num_workers++;
                pthread_t Ɵd;
                pthread_create(&Ɵd, NULL, worker, &worker_id);
            }
            break;
        case 3:
            if (num_workers == 0)
            {
                prinƞ("No workers available to handle work item\n");
            }
            else
            {
                while (num_work_items == MAX_THREADS)
                {
                    pthread_cond_wait(&cond, &mutex);
                }
                int work_item;
                prinƞ("Enter work item: ");
                scanf("%d", &work_item);
                work_queue[num_work_items] = work_item;
                num_work_items++;
                next_worker = (next_worker + 1) % num_workers;
                pthread_cond_signal(&cond);
            }
            break;
        default:
            prinƞ("Invalid command\n");
            break;
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t Ɵd[2];
    int id[2];
    id[0] = 0;
    id[1] = 1;
    pthread_create(&Ɵd[0], NULL, boss, &id[0]);
    pthread_create(&Ɵd[1], NULL, worker, &id[1]);
    for (int i = 0; i < 2; i++)
    {
        pthread_join(Ɵd[i], NULL);
    }
    return 0;
}


#include <stdio.h>
#include <pthread.h>
void *fun_t(void* arg){
    int ret;

    ret = pthread_exit("bye");
    printf("%d",ret);
}

int main(){
    pthread_t pt;
    void *res_t;
    if(pthread_create(&pt,NULL,fun_t,NULL)!=0)
     perror("pthread_create");
    
    if(pthread_join(pt,&res_t)!=0)
      perror("pthread_joi");
    return 0;
}