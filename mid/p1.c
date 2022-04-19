#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int main() {
    FILE *fp, *fp1; //file pointers
    fp = fopen(__FILE__, "r"); //read source file
    int num_lines=0, i;
    char line[500], temp[] = ".txt";
    //count number of lines
    while(fgets(line, sizeof(line), fp)){
        num_lines++;
    }
    fclose(fp); //close file

    //print number of lines
    printf("Number of lines: %d\n", num_lines);

    //open file again
    fp = fopen(__FILE__, "r");

    for(i=1; i<=num_lines; i++){
        //read one line from source file
        fgets(line, sizeof(line), fp);

        //make child process
        if(fork() == 0){
            //convert int to string
            int length = snprintf( NULL, 0, "%d", i);
            char* str = malloc( length + 1 );
            snprintf(str, length + 1, "%d", i);
            //make file name as num.txt
            strcat(str, temp);
            //open new file
            fp1 = fopen(str, "w+");
            //put line in file
            fputs(line, fp1);
            //close file
            fclose(fp1);
            //terminate child process
            exit(0);
        }
    }
    fclose(fp); //close source file reading
}