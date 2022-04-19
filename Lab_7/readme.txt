CS342 OS Lab

1901CS44
Pushpendra Nagle

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

>>Q1
Run command:
gcc p1.c -lpthread
./a.out

Output:
Reader 1: read val as 0
Reader 2: read val as 0
Reader 3: read val as 0
Reader 4: read val as 0
Reader 5: read val as 0
Writer 1 modified val to 10
Writer 2 modified val to 20

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

>>Q2
Here are code samples for two threads that use binary semaphores. Give a sequence of
execution and context switches in which these two threads can deadlock. Write a C program
proposing a change to one or both of them such that it makes deadlock impossible.
>>Sol
semaphore *mutex, *data;
    void A() {
    wait(mutex);
    wait(data);
    print(“process A”)
    signal(mutex);
    signal(data);
}
void B() {
    wait(data);
    wait(mutex);
    print(“process B”)
    signal(data);
    signal(mutex);
}

Now if the first thread executes wait(mutex) in void A() and second thread executes wait(data) in void B(), then when the 
second thread reaches wait(mutex) in void B() and the first thread reaches wait(data) in void A(), we will go into a deadlock situation. 
First thread is waiting on the second to release data and second is waiting for first to release mutex.

We can solve this problem by using identical sequence of acquiring semaphores.
semaphore *mutex, *data;
    void A() {
    wait(mutex);
    wait(data);
    print(“process A”)
    signal(mutex);
    signal(data);
}
void B() {
    wait(mutex);
    wait(data);
    print(“process B”)
    signal(mutex);
    signal(data);
}

In the code given above, both semaphores are acquired in the same order, so if one thread aquires mutex then the same thread will
aquire data also, hence deadlock will not occur.

Run command:
gcc p2.c -lpthread
./a.out

Output:
This is Thread 1 printing Process A
This is Thread 1 printing Process A
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 2 printing Process B
This is Thread 1 printing Process A
This is Thread 1 printing Process A
This is Thread 1 printing Process A

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

>>Q3

Run command:
gcc p3.c -lpthread
./a.out

Output:
No more slices left. Student 1 is odering pizza.
Waiting. Student 1 is sleeping.
Waiting. Student 3 is sleeping.
Waiting. Student 2 is sleeping.
Waiting. Student 4 is sleeping.
Waiting. Student 5 is sleeping.
Waiting. Student 6 is sleeping.
Waiting. Student 7 is sleeping.
Pizza delivered.
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
No more slices left. Student 7 is odering pizza.
Waiting. Student 7 is sleeping.
Waiting. Student 1 is sleeping.
Waiting. Student 2 is sleeping.
Waiting. Student 4 is sleeping.
Waiting. Student 5 is sleeping.
Waiting. Student 6 is sleeping.
Pizza delivered.
Slice taken. Student 6 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 6 is eating pizza and studying
Slice taken. Student 7 is eating pizza and studying
Slice taken. Student 1 is eating pizza and studying
No more slices left. Student 1 is odering pizza.
Waiting. Student 1 is sleeping.
Waiting. Student 2 is sleeping.
Waiting. Student 5 is sleeping.
Pizza delivered.
Slice taken. Student 5 is eating pizza and studying
Slice taken. Student 8 is eating pizza and studying
Slice taken. Student 6 is eating pizza and studying
Slice taken. Student 6 is eating pizza and studying
Slice taken. Student 5 is eating pizza and studying

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++