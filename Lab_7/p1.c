#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
typedef void* address_t;

sem_t lock;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int val = 0;
int n_reader = 0;

void *writer_func(void *wno);
void *reader_func(void *rno);

int main(){   
    pthread_t reader[5],writer[2];
    sem_init(&lock,0,1);
    int arg[10];
    //create threads
    for(int i = 0; i < 5; i++) {
        arg[i]=i+1;
        pthread_create(&reader[i], NULL, (void *)reader_func, (void *)&arg[i]);
    }
    for(int i = 0; i < 2; i++) {
        pthread_create(&writer[i], NULL, (void *)writer_func, (void *)&arg[i]);
    }
    //join threads
    for(int i = 0; i < 5; i++) {
        pthread_join(reader[i], NULL);
    }
    for(int i = 0; i < 2; i++) {
        pthread_join(writer[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&lock);
    return 0; 
}

void *writer_func(void *wno){   
    sem_wait(&lock);
    val = val+10; //write the value
    printf("Writer %d modified val to %d\n",(*((int *)wno)),val);
    sem_post(&lock);
}

void *reader_func(void *rno){   
    pthread_mutex_lock(&mutex);
    n_reader++;
    printf("Reader %d: Started reading\n",*((int *)rno));
    if(n_reader == 1) { //first reader
        sem_wait(&lock); //block writer
    }
    pthread_mutex_unlock(&mutex);
    
    printf("Reader %d: read val as %d\n",*((int *)rno),val);
    pthread_mutex_lock(&mutex);
    n_reader--;
    if(n_reader == 0) {//last reader
        sem_post(&lock);//wake writer
    }
    printf("Reader %d: Finished reading\n",*((int *)rno));
    pthread_mutex_unlock(&mutex);
}