#include <stdio.h>

// Function for binary XOR
void calc_xor(int a, int b) {
    int temp1=a, temp2=b, res = 0, pwr = 1;

    //While any one is not zero
    while (temp1 != 0 || temp2 != 0) {
        // calculate xor of least significant bits
        int cur_xor = (temp1 % 2) * !(temp2 % 2) + !(temp1 % 2) * (temp2 % 2);
        // add to result
        res = res + (cur_xor * pwr);
        temp1 /= 2;
        temp2 /= 2;
        pwr *= 2;
    }
    printf("XOR of %d and %d = %d\n", a, b, res);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc == 3) {
        int a, b;
        sscanf(argv[1], "%d", &a);
        sscanf(argv[2], "%d", &b);
        //pass arguments to function to calculate xor
        calc_xor(a, b);
    }
    else {
        printf("Error: Enter 2 integers.");
    }
}
