//Lab 4
//Q1
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void parent_proc() {
    sleep(10);
    printf("Parent process.\n");
}

void child_proc() {
    printf("Child process.\n");
}

int main() {
    printf("Prog id: %d\n", getpid());
    printf("Enter n: ");
    int n,i;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        pid_t PID = fork();
        if(PID<0) {
            printf("Fork failed.\n");
            return 1;
        }
        if(PID>0) {
            sleep(2);
        }
        if(PID==0) {
            printf("Child id: %d\n", getpid());
            exit(0);
        }
    }
    sleep(60);
}