CS342
OS Lab
Lab - 9

Pushpendra Nagle
1901CS44

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

>>Q1
Run command:
g++ q1.c
./a.out

Inputs:
Enter frame size: 3
Enter number of page requests: 10
Enter the page requests separated by space:
4 7 6 1 7 6 1 2 7 2

Output:
Optimal:
X X X at time 0
4 X X at time 1
4 7 X at time 2
4 7 6 at time 3
1 7 6 at time 4
1 7 6 at time 5
1 7 6 at time 6
1 7 6 at time 7
2 7 6 at time 8
2 7 6 at time 9
2 7 6 at time 10
        Page faults : 5

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

>>Q2
Run command:
g++ q2.cpp
./a.out

Inputs:
Enter frame size: 3
Enter page sequence size: 10
4 7 6 1 7 6 1 2 7 2

Output:
4 7 6 at time 1
4 7 6 at time 2
4 7 6 at time 3
1 7 6 at time 4
1 7 6 at time 5
1 7 6 at time 6
1 7 6 at time 7
1 2 7 at time 8
1 2 7 at time 9
1 2 7 at time 10

Faults = 3


Inputs:
Enter frame size: 4
Enter page sequence size: 16
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5

Output:
1 2 3 4 at time 1
1 2 3 4 at time 2
1 2 3 4 at time 3
1 2 3 4 at time 4
1 2 3 4 at time 5
2 7 5 1 at time 6
2 7 5 1 at time 7
2 7 5 1 at time 8
2 7 5 1 at time 9
1 6 4 7 at time 10
1 6 4 7 at time 11
1 6 4 7 at time 12
2 1 5 7 at time 13
2 1 5 7 at time 14
2 1 5 7 at time 15
2 1 5 7 at time 16

Faults = 4


Remarks: It can be seen that it performs better than existing page replacement algos
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++