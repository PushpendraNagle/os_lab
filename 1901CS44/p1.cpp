//1901CS44
#include<bits/stdc++.h>
using namespace std;

int p,v,f; //physical memory, virtual memory, frame memory
//frame_check[i] = 1 -> not free
//frame_check[i] = 0 -> free
unordered_map<int,int>page_table; //key is page no., value is frame no.
unordered_map<int,int>frame_check;
int frame=0, page=0;

//Used to allocate process bytes
void allocate(int proc_size){
    int frames_req = proc_size/(1<<f); //calculate number of frames required
    int i=0;
    while(frames_req){
        if(frame_check[i] == 0){ //if frame empty
            frame_check[i] = 1; //mark as full now
            page_table[page] = i;  //allocate page to frame
            cout<<"Page "<<page<<" allocated to frame "<<i<<'\n';
            i++;
            page++;
            frames_req--;
        }else{
            i++; //keep checking for empty frames
        }
    }
    
}

//Used to translate logical addr to physical addr
void translate(int logical_addr){
    long long offset = 0;
    long long page_no = 0;
    //Page no. is from the fth bit to vth bit
    for(int i=f; i<v; i++){
        if((1<<i) & logical_addr){
            page_no+=(1<<(i-f));
        }
    }
    //Check if page is present
    if(page_table[page_no]==0){
        cout<<"Invalid Page Number.\n";
    }else{
        cout<<"Physical address is ";
        long long frame_no = page_table[page_no]; //find corresponding frame number
        long long p_addr = 0;
        //add offset
        for(int i=0; i<f; i++){
            if(logical_addr & (1<<i)){
                p_addr+=(1<<i);
            }
        }
        //add frame number
        for(int i=0; i<(p-f); i++){
            if(frame_no & (1<<i)){
                p_addr+=(1<<(i+f));
            }
        }
        //print physical addr
        cout<<p_addr<<'\n';
    }
}

void delete_page(int page_no){
    int temp = page_table[page_no];
    frame_check[temp]=0; //mark frame as empty where the page was stored
    page_table[page_no]=0; //free memory

    cout<<"Deleted Page "<<page_no<<'\n';
}

int main(){
    cout<<"Enter values of p, v and f respectively with space in between: ";
    cin>>p>>v>>f; //take input
    cout<<"Enter value of n: ";
    int n;
    cin>>n;
    cout<<"Enter 2*n integers specifying the range already occupied: ";
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        for(int j=a; j<=b; j++){
            frame_check[j]=1;
        }
    }
    cout<<"Enter the number of queries: ";
    int q;
    cin>>q;
    cout<<"Enter queries one by one: \n";
    while(q--){
        char choice; cin>>choice;
        int temp; cin>>temp;
        if(choice=='a'){
            allocate(temp);
        }else if(choice=='t'){
            translate(temp);
        }else if(choice=='d'){
            delete_page(temp);
        }
    }
}