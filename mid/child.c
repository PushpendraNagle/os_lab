#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[])
{ 
    printf("\nChild # %s: I am a %s, and my name is %s.", argv[0],argv[1],argv[2]);
    return 0;
}