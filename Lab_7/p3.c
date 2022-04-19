#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
typedef void* address_t;

int n_slices=0, flag=1, take_pizza=1;
pthread_cond_t make_order = PTHREAD_COND_INITIALIZER;
pthread_cond_t do_delivery = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void student(void* id)
{
    while(1){
        pthread_mutex_lock(&mutex);
        while(take_pizza){
            if(n_slices > 0){ //slice available
                n_slices--; //take slice
                take_pizza=0; //
                printf("Slice taken. Student %d is eating pizza and studying\n",(*((int*)id)));
            }else{
                if(flag){
                    printf("No more slices left. Student %d is odering pizza.\n", (*((int*)id)));
                    pthread_cond_signal(&make_order);
                    flag=0;
                }
                printf("Waiting. Student %d is sleeping.\n", (*((int*)id)));
                pthread_cond_wait(&do_delivery, &mutex);
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
        take_pizza=1;
    }
}

void pizza_delivery(){
    while(1){
        pthread_mutex_lock(&mutex);
        printf("Pizza delivered.\n");
        n_slices = 5;
        flag=1;
        pthread_cond_broadcast(&do_delivery);
        pthread_cond_wait(&make_order, &mutex);
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t tid[8];
    int thread_ID[8],i;
    //create student threads
    for(i=0; i<8; i++){
        thread_ID[i]=i+1;
        pthread_create(&tid[i], NULL, (void*)student, (void*)&thread_ID[i]);
    }
    
    //create pizzashop thread
    pthread_t pizzashop;
    pthread_create(&pizzashop, NULL, (void*)pizza_delivery, NULL);
    sleep(30);
}