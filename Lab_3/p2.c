//Lab 3 Q2
//1901CS44
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int func() {
    fork();
    fork();
}

int main() {
    func();
    printf("Hello ");
    printf("Hello ");
    exit(0);
}
