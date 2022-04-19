Lab 5

Pushpendra Nagle
1901CS44

>>Q1
Run command: gcc p1.c -lpthread
./a.out

Output:
Thread 3: Hello World!
Thread 0: Hello World!
i = 0, status = Thread 0
Thread 2: Hello World!
i = 2, status = Thread 2
Thread 5: Hello World!
i = 5, status = Thread 5
Thread 7: Hello World!
i = 7, status = Thread 7
Thread 8: Hello World!
i = 8, status = Thread 8
Thread 1: Hello World!
i = 1, status = Thread 1
i = 3, status = Thread 3
Thread 4: Hello World!
i = 4, status = Thread 4
Thread 6: Hello World!
i = 6, status = Thread 6
i = 9, status= CANCELLED

>>Q2
Run command: gcc p2.c -lpthread
./a.out

Output:
Enter number of lines to write: 25
Attempting to create test.txt file....
File created/accessed.
Writing to file test.txt
Reading file test.txt
Thread 3 -> Read 10 characters from line 1
Thread 3 -> Read 10 characters from line 2
Thread 3 -> Read 10 characters from line 3
Thread 3 -> Read 14 characters from line 4
Thread 3 -> Read 10 characters from line 5
Thread 3 -> Read 14 characters from line 6
Thread 3 -> Read 10 characters from line 7
Thread 3 -> Read 14 characters from line 8
Thread 3 -> Read 14 characters from line 9
Thread 3 -> Read 14 characters from line 10
Thread 3 -> Read 10 characters from line 11
Thread 3 -> Read 14 characters from line 12
Thread 3 -> Read 10 characters from line 13
Thread 3 -> Read 14 characters from line 14
Thread 3 -> Read 14 characters from line 15
Thread 3 -> Read 14 characters from line 16
Thread 3 -> Read 10 characters from line 17
Thread 3 -> Read 14 characters from line 18
Thread 3 -> Read 10 characters from line 19
Thread 3 -> Read 14 characters from line 20
Thread 3 -> Read 14 characters from line 21
Thread 3 -> Read 14 characters from line 22
Thread 3 -> Read 10 characters from line 23
Thread 3 -> Read 14 characters from line 24
Thread 3 -> Read 14 characters from line 25

>>Q3
Run command: gcc p3.c -lpthread
./a.out

Output:
Enter number of petrol vending machines: 2
Enter queue size at vending machine: 10
Enter total petrol available: 100
Enter petrol needed by 10 customers at machine 1: 1 2 3 4 5 6 7 8 9 10
Enter petrol needed by 10 customers at machine 2: 11 12 13 14 15 16 17 18 19 20
Dispensed 1 , Remaining: 99
Dispensed 11 , Remaining: 88
Dispensed 2 , Remaining: 86
Dispensed 12 , Remaining: 74
Dispensed 3 , Remaining: 71
Dispensed 13 , Remaining: 58
Dispensed 4 , Remaining: 54
Dispensed 14 , Remaining: 40
Dispensed 5 , Remaining: 35
Dispensed 15 , Remaining: 20
Dispensed 6 , Remaining: 14
Dispensed 7 , Remaining: 7