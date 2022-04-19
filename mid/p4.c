#include <pthread.h>   
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NUMTHREAD 3 

void * depositor(int *id);
void * withdrawer(int *id);
void * hacker(int *id);

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t belowamt  = PTHREAD_COND_INITIALIZER;
pthread_cond_t belowLimit  = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD]  = {0,1,2};
int i = 1, j = 1, MAX, transaction_no=0;

/* shared variable */
int balance = 100;
int amt;

int main(){
    int i;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amt);
    printf("Enter transactions after which hacker will become active: ");
    scanf("%d", &MAX);
    pthread_t thread[NUMTHREAD];
    //create threads
    pthread_create(&thread[0], NULL, (void *)hacker, &thread_id[0]);
    pthread_create(&thread[1], NULL, (void *)depositor, &thread_id[1]);
    pthread_create(&thread[2], NULL, (void *)withdrawer, &thread_id[2]);
    for(i=0; i< NUMTHREAD ; i++){
        pthread_join(thread[i], NULL);
    }
}

void * depositor(int *id){
    int deposit;
    while(j < 100){
        if(transaction_no == MAX)
            pthread_cond_signal(&belowLimit); //signal hacker
        deposit = (double)(rand() % 200); //random aount to deposit
        pthread_mutex_lock(&count_mutex); //mutex lock
        balance += deposit;
        printf("Transaction no: %d. Thread id-%d deposited %d. Balance: %d\n",++transaction_no, * id, deposit, balance);
        fflush(stdout);
        j++;
        if(transaction_no == MAX)
            pthread_cond_signal(&belowLimit); //signal hacker
        if (balance >= amt)
            pthread_cond_signal(&belowamt); //signal withdrawer
        pthread_mutex_unlock(&count_mutex); //mutex unlock
        sleep(1);
    }
}

void * withdrawer(int *id){
    pthread_mutex_lock(&count_mutex);
    while (i < 100){
        if(transaction_no == MAX)
            pthread_cond_signal(&belowLimit); //signal hacker
        if (balance < amt ) 
            pthread_cond_wait(&belowamt, &count_mutex); //WT for signal from depositor
        balance -= amt;
        printf("Transaction no: %d. Thread id-%d withdrew %d. Balance: %d\n",++transaction_no,* id, amt, balance);
        fflush(stdout);
        printf("Enter amount to withdraw: "); //take input for amount to withdraw
        scanf("%d", &amt);
        i++;
        if(transaction_no == MAX)
            pthread_cond_signal(&belowLimit); //signal hacker
        sleep(1);
    }
    pthread_mutex_unlock(&count_mutex); //mutex unlock
}

void * hacker(int *id){
    pthread_cond_wait(&belowLimit, &count_mutex); //WT for transaction limit to reach
    printf("Box has been hacked by hacker with thread id-%d\n", *id);
    exit(0);
}