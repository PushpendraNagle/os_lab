#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int n_child = argc/2;
    printf("I have %d children.\n",n_child);
    int j=0;
    for (int i = 0; i < n_child; i++) {
        char N[10000];
        sprintf(N,"%d", i+1);
        char *arg[]={N,argv[2*i+1],argv[2*i+2]};
        if(fork() == 0)
        {
            execv("child",arg);     
        }
    }
    sleep(1);
    printf("\nAll child process terminated. Parent exits.\n");
    return 0;
}