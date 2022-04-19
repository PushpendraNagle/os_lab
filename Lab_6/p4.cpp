#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
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
float AVG_TAT;
float AVG_WT;
int Total_TAT = 0;
int Total_WT = 0;
int burst_left[1000]; //remaining bust time
int is_done[1000]; //process completed or not
int cur_time = 0;
int completed = 0;

bool compare_by_completion(process p1, process p2) {  
    return p1.CT < p2.CT;
}

void HRTF(){
    while(completed != n) {
        int idx = -1;
        int mn = -1; //set mn to min value
        for(int i = 0; i < n; i++) {
			//find process with largest burst time 
            if(p[i].AT <= cur_time && is_done[i] == 0 && burst_left[i] > mn) {
				mn = burst_left[i];
				idx = i;
			}
			if(p[i].AT <= cur_time && is_done[i] == 0 && burst_left[i] == mn && p[i].AT < p[idx].AT) {
				mn = burst_left[i];
				idx = i;
			}
        }

        if(idx == -1) {
			cur_time++; 
        }
        else {
			//burst left equals burst time, means we are starting process first time
            if(burst_left[idx] == p[idx].BT) {
                p[idx].ST = cur_time;
            }
            burst_left[idx] -= 1; //reduce by one
            cur_time++;
            
			//process completed
            if(burst_left[idx] == 0) {
                is_done[idx] = 1;
                completed++;
                p[idx].CT = cur_time;
                p[idx].TAT = p[idx].CT - p[idx].AT; //TAT = completion time - arrival time
                p[idx].WT = p[idx].TAT - p[idx].BT; //waiting time = TAT - burst time
                Total_TAT += p[idx].TAT;
                Total_WT += p[idx].WT;
            }
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
        burst_left[i] = p[i].BT; //initially burst time left = total burst time of process
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
	HRTF();
	print_result();
}