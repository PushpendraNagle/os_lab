//Lab 3 Q3
//1901CS44
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
                     
int main(int argc, char* argv[]) {
    //Seperate the two script names
    //and inputs to scripts
    char *argv1[argc - 2];  //arguments for task 1
    argv1[0] = argv[1];     //script name
    for (int i = 1; i < argc - 3; i++) {
        argv1[i] = argv[i + 1]; //script inputs
    }
    argv1[argc - 3] = NULL;

    char *argv2[3]; //arguments for task 2
    argv2[0] = argv[argc - 2]; //script name
	argv2[1] = argv[argc - 1]; //script input
	argv2[2] = NULL;

    //fork process
	pid_t PID = fork();

	// Parent (Task 2)
	if (PID) {
		char *script_name = argv[argc - 2];
		execv(script_name, argv2);
		printf("Error: Execution failed.\n");
	}
	// Child (Task 1)
	else {
		char *script_name = argv[1];
		execv(script_name, argv1);
		printf("Error: Execution failed.\n");
	}
	return 0;
}