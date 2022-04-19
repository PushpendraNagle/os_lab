#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
typedef void* address_t;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t data;

void A(void *thread_id){
    pthread_mutex_lock(&mutex);
    sem_wait(&data);
    printf("This is Thread %d printing Process A\n",(*((int *)thread_id)));
    pthread_mutex_unlock(&mutex);
    sem_post(&data);
}

void B(void *thread_id){
    pthread_mutex_lock(&mutex);
    sem_wait(&data);
    printf("This is Thread %d printing Process B\n",(*((int *)thread_id)));
    sem_post(&data);
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t threads[2];   
    sem_init(&data, 0, 1);           
    int thread_id[2]; 
    thread_id[0]=1;
    thread_id[1]=2;
    for (int i = 0; i < 20; i++){
        pthread_create(&threads[0], NULL, (void *)A, (void *)&thread_id[0]);
        pthread_create(&threads[1], NULL, (void *)B, (void *)&thread_id[1]);
    }
    pthread_mutex_destroy(&mutex); 
    sem_destroy(&data);    
    return 0;
}