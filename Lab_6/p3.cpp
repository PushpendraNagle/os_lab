#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;

struct process {
    int pid; //process id
    int AT; //arrival time
    int BT; //burst time
    int priority; //priority, less value means more priority
    int ST; //start time
    int CT; //completion time
    int TAT; //turnaround time
    int WT; //waiting time
};

int n; //number of processes
struct process p[1000];
float AVG_TAT;
float AVG_WT;
int Total_TAT = 0;
int Total_WT = 0;
int is_done[1000]; //process has been completed or not
int cur_time = 0;
int completed = 0;

bool compare_by_completion(process p1, process p2) {  
    return p1.CT < p2.CT;
}

void np_priority(){
    while(completed != n) {
        int idx = -1;
        int mn = 1e5; //set to max
        for(int i = 0; i < n; i++) {
            if(p[i].AT <= cur_time && is_done[i] == 0) {
                //find lowest value of priority
                if(p[i].priority < mn) {
                    mn = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mn && p[i].AT < p[idx].AT) {
                    mn = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            cur_time++; //increase cur time to match arrival time
        }
        else {
            is_done[idx] = 1; //process completed
            completed++;
            p[idx].ST = cur_time;
            p[idx].CT = p[idx].ST + p[idx].BT;
            p[idx].TAT = p[idx].CT - p[idx].AT; //TAT = completion time - arrival time
            p[idx].WT = p[idx].TAT - p[idx].BT; //waiting time = TAT - burst time
            Total_TAT += p[idx].TAT;
            Total_WT += p[idx].WT;
            cur_time = p[idx].CT;
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
        cin>>p[i].priority;
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
    np_priority();
    print_result();
}