//1901CS44
#include<bits/stdc++.h>
using namespace std;

//check if page is present in frame
bool find_page(vector<int>frame, int page, int m){
    for(int i=0; i<m; i++){
        if(frame[i] == page){
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cout<<"Enter frame size: ";
    cin>>m;
    cout<<"Enter page sequence size: ";
    cin>>n;
    vector<int>pageseq;
    vector<int>frame(m);
    for(int i=0; i<m; i++) frame[i]=-1;
    for(int i=0; i<n; i++){
        int temp; 
        cin>>temp;
        pageseq.push_back(temp);
    }
    int faults=0;
    int cur=0;

    for(int i=0; i<n; i++){
        if(!find_page(frame, pageseq[i], m)){ //if page fault occurs
            faults++;
            set<pair<int,int>>s;
            set<int>check;
            while(cur<n && (int)s.size()<m){ //select next 'm' distinct pages
                if(check.find(pageseq[cur])==check.end()){
                    check.insert(pageseq[cur]);
                    s.insert({cur, pageseq[cur]});
                }
                cur++;
            }
            int j=0;
            for(auto it:s){ //add them to the frame
                frame[j++]=it.second;
            }
        }

        //print frame contents
        int k=min((int)frame.size(), i+1);
        int p=0;
        for(auto it:frame){
            p++;
            cout<<it<<" ";
        }
        cout<<"at time "<<i+1<<"\n";
    }
    cout<<"\nFaults = "<<faults<<"\n";
}