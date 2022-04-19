//Lab 3 Q1
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("Error: Invalid input.\n");
		return 1;
	}

    int a, b, fd1[2], fd2[2]; // File Descriptor for Child 1 and 2
	
	//take input
    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);



    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
		printf("Error: Pipe connection failed.");
		return 1;
	}

    pid_t process_id = fork();
    if (process_id < 0) {
		printf("Error: Fork failed.");
		return 1;
	}

    // Parent process
    if (process_id) {
    	int sum, product;
		//read from file descriptor
    	read(fd1[0], &sum, sizeof(int));
    	read(fd2[0], &product, sizeof(int));
    	printf("Parent process_id = %d Division = %d\n", getpid(), product / sum);
    } 
    else {
		//fork again
    	process_id = fork();
    	if (process_id < 0) {
			printf("Error: Fork failed.");
			return 1;
		}
    	// Child 1
    	if (process_id) {
    		int temp = a + b;
    		printf("Child process_id = %d Sum = %d\n", getpid(), temp);
			//write to file descriptor
    		write(fd1[1], &temp, sizeof(int));
    	}
    	// Child 2
    	else {
    		int temp = a * b;
    		printf("Child process_id = %d Multiplication = %d\n", getpid(), temp);
			//write to file descriptor
    		write(fd2[1], &temp, sizeof(int));
    	}
    }
    return 0;
}