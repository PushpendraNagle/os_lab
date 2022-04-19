CS342
Assignment 8
22-03-2022

Pushpendra Nagle
1901CS44


>>Q1
Run command:
g++ bankers.cpp
./a.out

Inputs:
Enter number of processes: 5
Enter number of resources: 3
Enter the amount of available resources
Resource-1: 3
Resource-2: 3
Resource-3: 2
Enter the max matrix
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Output:
Safe Sequence-1: P2 P4 P1 P3 P5
Safe Sequence-2: P2 P4 P1 P5 P3
Safe Sequence-3: P2 P4 P3 P1 P5
Safe Sequence-4: P2 P4 P3 P5 P1
Safe Sequence-5: P2 P4 P5 P1 P3
Safe Sequence-6: P2 P4 P5 P3 P1
Safe Sequence-7: P2 P5 P4 P1 P3
Safe Sequence-8: P2 P5 P4 P3 P1
Safe Sequence-9: P4 P2 P1 P3 P5
Safe Sequence-10: P4 P2 P1 P5 P3
Safe Sequence-11: P4 P2 P3 P1 P5
Safe Sequence-12: P4 P2 P3 P5 P1
Safe Sequence-13: P4 P2 P5 P1 P3
Safe Sequence-14: P4 P2 P5 P3 P1
Safe Sequence-15: P4 P5 P2 P1 P3
Safe Sequence-16: P4 P5 P2 P3 P1