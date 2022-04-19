//Lab 4
//Q2
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
            if(i==n-1)
                exit(0);
        }
        if(PID==0) {
            sleep(1);
            printf("I am Child/orphan with id: %d and my parent id is %d\n", getpid(), getppid());
            exit(0);
        }
    }
}