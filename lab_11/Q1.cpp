//1901CS44
#include<bits/stdc++.h>
using namespace std;

int head = 100;
vector<int>q;
map<int,string>temp;
int N;
int HIGH=199;
int LOW=0;

void plot_gnu(vector<int>v){
    FILE *gnuplot = popen("gnuplot", "w");
    if(!gnuplot){
        exit(1);
    }
    fprintf(gnuplot, "plot '-' u 1:2 t 'Plot' w lp\n");
    for(int i=0; i<N; i++){
        fprintf(gnuplot,"%d %d\n",i+1,v[i]);
    }
    fprintf(gnuplot,"e\n");
    fprintf(stdout,"Click Ctrl+d to quit...\n");
    fflush(gnuplot);
    getchar();
    pclose(gnuplot);
}

void FCFS(){
    vector<int>x(N+1),y(N+1);
    q[0]=head;
    int THM=0;
    for(int i=0; i<N; i++){
        THM+=abs(q[i]-q[i+1]);
    }
    cout<<"FCFS - "<<THM<<" \n";
    temp[THM*5]="FCFS";
}

void SCAN(){
    vector<int>v(N+1);
    v[0]=head;
    for(int i=1; i<N+1; i++){
        v[i]=q[i];
    }
    sort(v.begin(), v.end());
    int mx = v[N];
    int idx=-1;
    for(int i=0; i<=N; i++){
        if(head == v[i]){
            idx=i;
            break;
        }
    }
    if(abs(head-LOW) <= abs(head-HIGH)){
        for(int j=idx; j>=0; j--){
            cout<<v[j]<<"-->";
        }
        for(int j=idx+1; j<=N; j++){
            cout<<v[j]<<"-->";
        }
        cout<<"SCAN - "<<(head-LOW+mx-LOW)<<" \n";
    }else{
        for(int j=idx+1; j<=N; j++){
            cout<<v[j]<<"-->";
        }
        for(int j=idx; j>=0; j--){
            cout<<v[j]<<"-->";
        }
        cout<<"SCAN - "<<(HIGH-head+HIGH-v[0])<<" \n";
    }
    temp[(head+mx)*5] = "SCAN";
}

void CSCAN(){
    vector<int>v;
    v.push_back(head);
    for(int i=0; i<N; i++){
        v.push_back(q[i+1]);
    }
    v.push_back(HIGH);
    v.push_back(LOW);
    sort(v.begin(), v.end());
    int idx=-1;
    for(int i=0; i<=N; i++){
        if(v[i]==head){
            idx=i;
            break;
        }
    }
    int THM=0;
    for(int i=idx+1; i<=N+2; i++){
        cout<<v[i-1]<<"-->"<<v[i]<<" ";
        THM += abs(v[i]-v[i-1]);
    }
    for(int i=1; i<idx; i++){
        cout<<v[i-1]<<"-->"<<v[i]<<" ";
        THM += abs(v[i]-v[i-1]);
    }
    THM+=HIGH;
    cout<<"C-SCAN - "<<THM<<" \n";
    temp[(THM)*5] = "C-SCAN";
}

void SSTF()
{
	int curPos=100;
	int cur_head=0;
	int THM=0;
	set<int>sset;
	for(int i=1;i<=N;i++){
		sset.insert(q[i]);
	}

	while(!sset.empty()){
		int next_pos;
		set<int>::iterator it=sset.lower_bound(curPos);
		if(it==sset.end()){
			it--;
			next_pos=*it;
		}
		else{
			next_pos=*it;
			if(it!=sset.begin()){
				it--;
				if(abs(*it-curPos)<abs(next_pos-curPos)){
					next_pos=*it;
				}
			}
		}
		sset.erase(next_pos);
		cur_head+=abs(next_pos-curPos);
		THM+=5*abs(next_pos-curPos);
		curPos=next_pos;

	}
	cout<<"SSTF - "<<cur_head<<"\n";
    temp[THM] = "SSTF";
}

int main(){
    cout<<"Enter N: ";
    cin>>N;
    cout<<"Enter "<<N<<" numbers: ";
    q.push_back(1);
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        q.push_back(temp);
    }
    FCFS();
    SCAN();
    CSCAN();
    SSTF();
    cout<<"Sorted order:\n";
    for(auto it:temp){
        cout<<it.second<<" "<<it.first<<"\n";
    }




}