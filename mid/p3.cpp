#include <bits/stdc++.h>
using namespace std;

typedef struct pr{
    int pid;
    int BT;
    int AT;
    int FT;
    int TAT;
    int WT;
    int PRT;
    int RT;
} process;

vector<int> process_order;

// comparator to sort processes according to AT time
bool sort_by_arrival(process p1, process p2){
    if (p1.AT == p2.AT)
        return p1.pid < p2.pid;
    return p1.AT < p2.AT;
}

// fn to implement multilevel queue scheduling algorithm
void MLQ(vector<process> &proc){
    int CNT = 0;
    int n = proc.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> system_queue, user_queue;
    deque<int> q;
    for (int i = 0; i < n; i++){
        if (proc[i].PRT == 1)
            system_queue.push({proc[i].AT, CNT++, proc[i].pid});
        else
            user_queue.push({proc[i].AT, CNT++, proc[i].pid});
    }
    int time = 0; 
    while (time < 10000&&(!system_queue.empty()||(!user_queue.empty()))){
        int aq1=INT_MAX,aq2=INT_MAX;
        if(!system_queue.empty()){
            aq1=system_queue.top()[0];
        }
        if(!user_queue.empty()){
            aq2=user_queue.top()[0];
        }
        time=max(min(aq1,aq2),time);
        if (!system_queue.empty() && aq1 <= time){
            auto u1=system_queue.top();
            system_queue.pop();
            int i = u1[2] - 1;
            if (proc[i].RT > 4){   
                proc[i].RT -= 4;          
                time += 4;
                system_queue.push({time, CNT++, i + 1});
            }
            else{
                process_order.push_back(i + 1);
                time += proc[i].RT;
                proc[i].RT = 0;                
                proc[i].FT = time;
                proc[i].TAT = proc[i].FT - proc[i].AT;
                proc[i].WT = proc[i].FT - proc[i].AT - proc[i].BT;
                
            }
        }
        else if(!user_queue.empty()){
            auto u2=user_queue.top();
            user_queue.pop();
            int i = u2[2] - 1;
            for (int j = 0; j < 3; j++){
                if (system_queue.empty()||(!system_queue.empty() && system_queue.top()[0] > time)){
                    time++;
                    proc[i].RT--;
                    if (proc[i].RT == 0){
                        process_order.push_back(i + 1);
                        proc[i].FT = time;
                        proc[i].TAT = proc[i].FT - proc[i].AT;
                        proc[i].WT = proc[i].FT - proc[i].AT - proc[i].BT;
                        break;
                    }
                    if(proc[i].RT!=0&&j==2){
                        user_queue.push({time, CNT++, i + 1});
                    }
                }
                else{
                    user_queue.push({time, CNT++, i + 1});
                    break;
                }
            }
        }
    }
}


int main(){
    cout << fixed << setprecision(6);
    int n, q;
    cin >> n>>q;
    vector<process> proc(n);
    for (int i = 0; i < n; i++){
        cin >> proc[i].AT;
        cin >> proc[i].BT;
        cin >> proc[i].PRT;
        proc[i].RT = proc[i].BT;
        proc[i].pid = i + 1;
    }
    MLQ(proc);
    int total_WT = 0, total_TAT = 0;
    for (int i = 0; i < n; i++){
        total_WT += proc[i].WT;
        total_TAT += proc[i].TAT;
    }
    cout << total_WT * 1.0 / n << " " << total_TAT * 1.0 / n << "\n";
    for (auto x : process_order)
        cout <<"P"<< x << " ";
    cout<<"\n";
    return 0;
}