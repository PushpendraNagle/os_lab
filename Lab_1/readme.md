CS342 OS Lab 1
1901CS44

Problem 1

Run command: ./p1.sh 1234
Output: 4321
Run command: ./p1.sh 102
Output: 201
Run command: ./p1.sh -904
Output: -409
Run command: ./p1.sh 987 123
Output: Error: Input should contain only one number.
Run command: ./p1.sh -10
Output: -1

Problem 2

Run command: ./p2.sh
Input A: 5
Input B: 8
Output: 5 6 7 8 
Run command: ./p2.sh
Input A: 7
Input B: 2
Output: Error: First number must be smaller than second.
Run command: ./p2.sh
Input A: -4
Input B: 0
Output: -4 -3 -2 -1 0 
Run command: ./p2.sh
Input A: 3
Input B: 3
Output: 3 

Problem 3

Run command: ./p3.sh test.txt 3
Output: Number of lines in file: 4
Run command: ./p3.sh test.txt 4
Output: Number of lines in file: 4
Run command: ./p3.sh test.txt 5
Output: Number of lines in file: 4
Less number of lines, deleting file.

Problem 4

Initially we have 2 files test.txt and testing.txt
We use '*' for current directory

Run command: ./p4.sh
Enter directory_path: *
Enter filename_pattern: test
Enter the new_filename: checked

Now file names have been changed to checked_1.txt and checked_2.txt


