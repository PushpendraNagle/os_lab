#include <iostream>
#include <algorithm> 
#include <iomanip> 
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

int n; //number of processes
struct process p[1000];
float AVG_TAT; //avg turnaround time
float AVG_WT; //avg waiting time
int Total_TAT = 0;
int Total_WT = 0;

bool compare_by_arrival(process p1, process p2) { 
    return p1.AT < p2.AT;
}
bool compare_by_completion(process p1, process p2) {  
    return p1.CT < p2.CT;
}

//First-come-first-serve
void FCFS(){
    sort(p,p+n,compare_by_arrival); //sort by arrival time
    for(int i = 0; i < n; i++) {
        p[i].ST = (i == 0)?p[i].AT:max(p[i-1].CT,p[i].AT); //for first process, start time = arrival time
        p[i].CT = p[i].ST + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT; //TAT = completion time - arrival time
        p[i].WT = p[i].TAT - p[i].BT; //waiting time = TAT - Burst time
        Total_TAT += p[i].TAT;
        Total_WT += p[i].WT;
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
    FCFS();
    print_result();
}