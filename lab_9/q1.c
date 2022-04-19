//1901CS44
#include<stdio.h>

//check if page is present in frame
int check(int size, int * arr, int value){
	int i;
	for(i=0;i<size;i++){
		if(arr[i] == value)
			return 1;
	}
	return 0;
}

//find closest index
int find_index(int size, int cur, int * arr,  int value){
	int i=cur;
	for(i++;i<size;i++){
		if(arr[i]==value){
			return i;
		}
	}
	return i;
}

//find minimum of closest index
int min_idx(int size, int * arr){
	int min_idx = 0;
	int i=0;
	int max=arr[0];
	for(i++;i<size;i++){
		if(arr[i] > max){
			max = arr[i];
			min_idx = i;
		}
	}
	return min_idx;
}

//print array
void printArray(int size, int * arr){
    int i=0;
    for(;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
	int n,m;
	printf("Enter frame size: ");
	scanf("%d", &m);
	printf("Enter number of page requests: ");
	scanf("%d", &n);
	int frames[m];
	int requests[n];
	printf("Enter the page requests separated by space: \n");
	int i;
	for(i=0;i<n;i++) scanf("%d", &requests[i]);
	int page_faults=0;
	int index=-1;
	printf("\nOptimal: \n");
	for(i=0;i<m;i++) frames[i] = -1;

    int nxt_idx[m];
	int frames_filled = 0;
	page_faults = 0;
    index = -1;

	//Initially all frames empty
	for(int j=0;j<m;j++){
		printf("X ");
	}
	printf("at time 0\n");

	//LRU
    for(i=0;i<n;i++){
		if(check(frames_filled, frames, requests[i])){ //if page present in frame
			for(int j=0;j<m;j++){
			if(frames[j]==-1)
				printf("X ");
			else
				printf("%d ", frames[j]);
			}
			printf("at time %d\n", i+1);
			continue;
		}
		else{ //not present in frame
			if(frames_filled == m){ //frame has no space, so replace
				int j=0;
				for(;j<m;j++){
					nxt_idx[j] = find_index(n, i, requests , frames[j]);
    			}
				int idx = min_idx(m, nxt_idx);
				frames[idx] = requests[i];
			}
			else{ //frame has space then add to frame
				frames[(++index)%m] = requests[i];
				frames_filled++;
			}
			page_faults++;
 		}
		//print frame contents
		for(int j=0;j<m;j++){
			if(frames[j]==-1)
				printf("X ");
			else
				printf("%d ", frames[j]);
		}
		printf("at time %d\n", i+1);
	}
    printf("\tPage faults : %d\n", page_faults);
}