#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
typedef void* address_t;

//Global variables
FILE *fp;
FILE *fp_read;
int N, lines_written, lines_read;

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2;

//Function to check prime
int not_prime(int n){
	for(int i=2;i<=n/2;i++){
		if(n%i!=0)
			continue;
		else
			return 1;
	}
	return 0;
}

//Thread 3 will read characters
void *read_file(void *arg) {
    while(lines_read < N){
        //If new line has been written
        if(lines_read < lines_written) {
            fflush(fp);
            //Count characters
            int cnt_char=0;
            char c=fgetc(fp_read);
			while (c!=EOF && c != '\n')
			{
				cnt_char++;
				c=fgetc(fp_read);
			}
            lines_read++;
			printf("Thread 3 -> Read %d characters from line %d\n", cnt_char, lines_read);
        }
    }
}

//Thread 1 will write on non-prime lines
void *task1(void *arg) {
    char str[] = "Non-prime line\n";
    //When we have written non-prime line
    //Signal to other thread to check next line
    pthread_mutex_lock(&mutex);
    while(lines_written < N){
        if(not_prime(lines_written+1)){
            //write line
            fputs(str, fp);
            lines_written++;
            //give signal
            pthread_cond_signal(&cond2);
        }else{
            //wait for signal
            pthread_cond_wait(&cond1, &mutex);
        }
    }
    pthread_mutex_unlock(&mutex);
}

//Thread 2 will write on prime lines
void *task2(void *arg) {
    char str[] = "Prime line\n";
    //When we have written prime line
    //Signal to other thread to check next line
    pthread_mutex_lock(&mutex);
    while(lines_written < N){
        if(!not_prime(lines_written+1)){
            //write line
            fputs(str, fp);
            lines_written++;
            //give signal
            pthread_cond_signal(&cond1);
        }else{
            //wait for signal
            pthread_cond_wait(&cond2, &mutex);
        }
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    //Take input
    printf("Enter number of lines to write: "); scanf("%d", &N);
    printf("Attempting to create test.txt file....\n");
    
    //Create and write to file
    fp = fopen("test.txt", "w+");
    if(fp != NULL){
        printf("File created/accessed. \nWriting to file test.txt\n");
    }else{
        return 1;
    }

    //Read file
    fp_read = fopen("test.txt", "r");
    if(fp_read != NULL){
        printf("Reading file test.txt\n");
    }else{
        return 1;
    }

    //Initialize mutex and conditions
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond1, NULL);
    pthread_cond_init(&cond2, NULL);

    //Create threads
    pthread_t threads[3];
    if(pthread_create(&threads[0], NULL, &task1, NULL) != 0){
        printf("Error.");
        return 1;
    }
    if(pthread_create(&threads[1], NULL, &task2, NULL) != 0){
        printf("Error.");
        return 1;
    }
    if(pthread_create(&threads[2], NULL, &read_file, NULL) != 0){
        printf("Error.");
        return 1;
    }

    //Wait for threads to terminate
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    //close file pointer
    fclose(fp);
    fclose(fp_read);
    //destroy mutex and cond
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond1);
    pthread_cond_destroy(&cond2);
}