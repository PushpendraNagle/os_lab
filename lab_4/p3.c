//Lab 4
//Q3
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void generate_lucas(int n) {
    FILE *fp1, *fp2;

    fp1 = fopen("temp.txt", "w+");
    if(n==1){
        putw(2, fp1);
    }else if(n==2){
        putw(2, fp1);
        putw(1, fp1);
    }else{
        putw(2, fp1);
        putw(1, fp1);
        int prev=1;
        int pre_prev=2;
        n-=2;
        while(n>0){
            int cur = prev + pre_prev;
            putw(cur, fp1);
            pre_prev = prev;
            prev = cur;
            n--;
        }
    }
    fclose(fp1);
    printf("Generated Lucas Sequence.\n\n");
}

void print_lucas(int n) {
    FILE *fp1, *fp2;
    int num;
    fp1 = fopen("temp.txt", "r");
    if(fp1 == NULL) {
        printf("Cannot read file.");
        exit(1);
    }
    printf("First %d numbers of Lucas sequence: ", n);
    while((num = getw(fp1)) != EOF){
        printf("%d ", num);
    }
    printf("\n\n");
    fclose(fp1);
}

int main() {
    printf("Enter n: ");
    int n;
    scanf("%d", &n);

    pid_t PID = fork();

    if(PID > 0) {
        pid_t PID2 = fork();
        //child 2
        if(PID2==0) {
            sleep(0.25);
            print_lucas(n);
        }
    }else if(PID == 0) {
        //child 1
        generate_lucas(n);
    }
}
