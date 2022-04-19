#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <queue> 
using namespace std;

struct process {
    int pid; //process id
    int AT; //arrival time
    int BT; //burst time
    int ST; //start time
    int CT; //completion time
    int TAT; //turnaround time
    int WT; //waiting time
};

int n, idx;
int tq=4; //Time Quantum
int cur_time = 0;
int completed = 0;
int vis[1000]; //visited process once
struct process p[1000];
queue<int> q;
float AVG_TAT;
float AVG_WT;
int Total_TAT = 0;
int Total_WT = 0;
int burst_left[1000];

bool compare_by_arrival(process p1, process p2) { 
    return p1.AT < p2.AT;
}
bool compare_by_completion(process p1, process p2) {  
    return p1.CT < p2.CT;
}

void check_proc(int flag){
    if(flag){
        //check process which are in ready state
        for(int i = 1; i < n; i++) {
            if(burst_left[i] > 0 && p[i].AT <= cur_time && vis[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }else{
        //check process
        for(int i = 1; i < n; i++) {
            if(burst_left[i] > 0) {
                q.push(i);
                vis[i] = 1;
                break;
            }
        }
    }
}

void Round_robin(){
    sort(p,p+n,compare_by_arrival); //sort by arrival
    for(int i = 0; i < n; i++) {
        burst_left[i] = p[i].BT; //initially, burst_left = burst time
    }
    vis[0] = 1; //mark process 1 as visited
    q.push(0); //push in queue
    while(completed != n) {
        idx = q.front(); //idx of process
        q.pop();
        
        //burst left == burst time. means we are just starting this process for first time
        if(burst_left[idx] == p[idx].BT) {
            p[idx].ST = max(cur_time,p[idx].AT);
            cur_time = p[idx].ST;
        }
        if(burst_left[idx]-tq > 0) {
            burst_left[idx] -= tq; //subtract time quantum from burst time
            cur_time += tq;
        }
        else {
            //burst left is less than time quantum so the process will end
            completed++;
            cur_time += burst_left[idx];
            burst_left[idx] = 0;
            p[idx].CT = cur_time;
            p[idx].TAT = p[idx].CT - p[idx].AT; //TAT = completion time - arrival time
            p[idx].WT = p[idx].TAT - p[idx].BT; //waiting time = TAT - burst time
            Total_TAT += p[idx].TAT;
            Total_WT += p[idx].WT;
        }
        check_proc(1); //check if new process are in ready states
        if(burst_left[idx] > 0) {
            q.push(idx);
        }
        if(q.empty()) {
            check_proc(0);
        }
    }
    AVG_TAT = (float) Total_TAT / n;
    AVG_WT = (float) Total_WT / n;
}

void take_input(){
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>p[i].AT;
        cin>>p[i].BT;
        p[i].pid = i+1;
    }
}

void print_result(){
    cout << setprecision(2) << fixed;
    cout<<AVG_WT<<" "<<AVG_TAT<<"\n";
    sort(p,p+n,compare_by_completion);
    for(int i = 0; i < n; i++) {
        cout<<"P"<<p[i].pid<<" ";
    }
}

int main() {
    take_input();
    Round_robin();
    print_result();
}