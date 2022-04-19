#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_THREADS 50

// Thread termination codes
const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

// Function that every thread will run
void* helloWorld(void* x) {
	int num = *(int *) x;
    printf("Thread %d: Hello World!\n",num);
    sleep(0.000000000000000000000001);
    printf("i = %d, status = Thread %d\n",num,num);
    return (void *)&SUCCESS; 
}

//function for checking cancel thread function
void* helloWorld2(void* x) {
	
    pthread_cancel(pthread_self());
    return (void *)&FAIL; 
}

int main() {
    pthread_t threads[10];
    int status[10];
    int args[10];
	// Creating arrays for thread IDs and arguments
	// Running threads
	for (int i = 0; i < 10; i++) {
		args[i] = i;
        if(i<9){
            status[i]=pthread_create(&threads[i], NULL, &helloWorld, (address_t)&args[i]);
        }else{
            status[i]=pthread_create(&threads[i], NULL, &helloWorld2, (address_t)&args[i]);
        }
	}
    //waiting for threads
    address_t statusp[10];
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i], &statusp[i]);
        if (status[i] != 0 || *(int *)statusp[i] != 0) {
			printf("i = %d, status= CANCELLED\n",i);
			exit(1);
		}
    }

	// Exiting main thread safely
	pthread_exit(NULL);
	return 0;
}