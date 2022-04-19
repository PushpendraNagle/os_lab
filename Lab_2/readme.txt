CS342
Lab 2
Pushpendra Nagle
1901CS44

Problem 1
Run command: ./p1.sh 2 4 6 6
Output: Success: Element found at 1 index.
Run command: ./p1.sh 5 2 4 6 7 8 6
Output: Success: Element found at 2 index.
Run command: ./p1.sh 5 2 4 6 7 8 10
Output: Error: Element not found.

Problem 2
Run command: ./p2.sh 10
Output: Result = 61689600
Run command: ./p2.sh 5
Output: Result = 1200
Run command: ./p2.sh 5 10
Output: Error: Multiple numbers entered.

Problem 3
Run command: ./p3.sh 3 5
Output: XOR of 3 and 5 = 6

Time comparision
Run command: time ./p3.sh 1234 4321
Output: XOR of 1234 and 4321 = 5171

real    0m0.047s
user    0m0.015s
sys     0m0.016s

Run command: gcc p3.c -o p3
time ./p3 1234 4321
Output: XOR of 1234 and 4321 = 5171

real    0m0.148s
user    0m0.000s
sys     0m0.031s

Observation: C code takes slightly more time as compared to shell code.

Problem 4
Run command: ./p4.sh abcd12??
Output: Password Entered: abcd12??
Length of Password: 8
<Strong and valid password>

Run command: ./p4.sh 12aabbcc
Output: Password Entered: 12aabbcc
Length of Password: 8
<Weak and invalid password>

Run command: ./p4.sh 12?a
Output: Password Entered: 12?a
Length of Password: 4
<Invalid password>
Must be atleast 7 characters long.

Run command: ./p4.sh 12???????
Output: Password Entered: 12???????
Length of Password: 9
<Weak and invalid password>

