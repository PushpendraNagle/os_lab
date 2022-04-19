#include "bits/stdc++.h"
using namespace std;

int N,M;
vector<vector<int>>safe_seqs;
vector<vector<int>>allocated;
vector<vector<int>>maximum;
vector<vector<int>>need;
vector<int>available;

//Add allocated resources to available resources
void add_alloc(int i){
    for(int j=0; j<M; j++){
        available[j] += allocated[i][j];
    }
}

//Subtract allocated resources from available resources
void sub_alloc(int i){
    for(int j=0; j<M; j++){
        available[j] -= allocated[i][j];
    }
}

//Function to check availability of resources
bool check_availability(int i){
    bool check=true;
    for(int j=0; j<M; j++){
        if(need[i][j] > available[j])
            check = false;
    }
    return check;
}

//Function to calculate safe sequences
void find_safe_seq(vector<int>seq, vector<bool>visited){
    for(int i=0; i<N; i++){
        if(!visited[i] && check_availability(i)){ //if not visited and if resources are available
            visited[i]=true;
            seq.push_back(i);
            add_alloc(i);

            //recurse and find sequence
            find_safe_seq(seq, visited);

            seq.pop_back();
            visited[i]=false;
            sub_alloc(i);
        }
    }
    //Add sequence
    if(seq.size() == N){
        safe_seqs.push_back(seq);
    }
}

//calculate need matrix
void calc_need(){
    vector<int>temp(M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp[j] = maximum[i][j] - allocated[i][j];
        }
        need.push_back(temp);
    }
}

int main(){
    cout<<"Enter number of processes: ";
    cin>>N;
    cout<<"Enter number of resources: ";
    cin>>M;
    vector<bool>visited(N,false);
    
    //Take input
    cout<<"Enter the amount of available resources\n";
    for(int i=0; i<M; i++){
        cout<<"Resource-"<<i+1<<": ";
        int temp_v; cin>>temp_v;
        available.push_back(temp_v);
    }
    vector<int>temp(M);
    cout<<"Enter the max matrix\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>temp[j];
        }
        maximum.push_back(temp);
    }
    cout<<"Enter the allocation matrix\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>temp[j];
        }
        allocated.push_back(temp);
    }

    //calculate the need matrix
    calc_need();

    temp.clear();

    //call function to calculate safe sequences
    find_safe_seq(temp,visited);

    //If no safe sequence
    if(safe_seqs.size() == 0){
        cout<<"No safe sequence found!\n";
    }else{ //Print safe sequences
        int cnt=0;
        for(auto i:safe_seqs){
            cout<<"Safe Sequence-"<<++cnt<<": ";
            for(auto j:i){
                cout<<"P"<<j+1<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}