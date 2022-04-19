#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
typedef void* address_t;

//Global variables
int M,N; 
int total_petrol;
pthread_mutex_t mutex;
pthread_cond_t cond;

//Function to dispense petrol
void *dispense_petrol(void *brr) {
    //Litres needed
    int *needed = (int *) brr;
    int i;
    for(i=0; i<N; i++) {
        //Apply lock
        pthread_mutex_lock(&mutex);
        if(needed[i] <= total_petrol){
            total_petrol -= needed[i];
            printf("Dispensed %d , Remaining: %d\n", needed[i], total_petrol);
        }
        pthread_cond_signal(&cond); //Give signal
        if(i+1<N && needed[i+1]<=total_petrol && M>1) pthread_cond_wait(&cond, &mutex); //wait for signal
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    //Take input
    printf("Enter number of petrol vending machines: "); scanf("%d", &M);
    int i,j; printf("Enter queue size at vending machine: "); scanf("%d", &N);
    printf("Enter total petrol available: "); scanf("%d", &total_petrol);
    int arr[M][N];
    for(i=0; i<M; i++){
        printf("Enter petrol needed by %d customers at machine %d: ", N, i+1);
        for(j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    //Initialize mutex and cond
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    //Create threads
    pthread_t machines[M];
    for(i=0; i<M; i++){
        if(pthread_create(&machines[i], NULL, &dispense_petrol, arr[i]) != 0) {
            printf("Error encountered.\n");
            return 1;
        }
    }

    //Wait for threads
    for(i=0; i<M; i++){
        if(pthread_join(machines[i], NULL) != 0) {
            printf("Error encountered.\n");
            return 2;
        }
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_exit(NULL);
}