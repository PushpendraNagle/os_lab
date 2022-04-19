//Lab 4
//Q4
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void source_copy() {
    FILE *fp1, *fp2;
    char c;
    fp1 = fopen(__FILE__, "r");
    if(fp1 == NULL) {
        printf("Cannot read file.");
        exit(1);
    }
    fp2 = fopen("f2.txt", "w+");
    if(fp2 == NULL) {
        printf("Cannot open f2.txt");
        exit(1);
    }
    c = fgetc(fp1);
    while(c != EOF) {
        fputc(c, fp2);
        c = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    printf("Copied source code to f2.txt file.\n\n");
}

void print_content() {
    FILE *fp1, *fp2;
    char c;
    fp1 = fopen("f2.txt", "r");
    if(fp1 == NULL) {
        printf("Cannot read file.");
        exit(1);
    }
    c = fgetc(fp1);
    while(c != EOF) {
        printf("%c", c);
        c = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}

void delete_file() {
    if(remove("f2.txt")==0) {
        printf("File deleted successfully.\n");
    }else{
        printf("Error: Cannot delete file.\n");
    }
}

int main() {
    pid_t PID = fork();

    if(PID > 0) { //parent
        source_copy();
    }else if(PID == 0) { //child
        pid_t PID2 = fork();

        if(PID2 > 0) { //parent
            sleep(1);
            print_content();
        }else if(PID2 == 0) { //child
            sleep(2);
            delete_file();
        }
    }
}
