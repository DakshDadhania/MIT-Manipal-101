#include <iostream>
using namespace std;

void order(int parrival[],int parr[],int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-i-1;j++){
			if(parrival[j]>parrival[j+1]){
				int temp = parrival[j];
				parrival[j] = parrival[j+1];
				parrival[j+1] = temp;
				temp = parr[j];
				parr[j] = parr[j+1];
				parr[j+1] = temp;
			}
			cout << "h";
		}
	}	
}
int small(int parr[],int n,int parrival[],int completed[],int arrival){
	int x = 0;
	while(completed[x] == 1){
		x++;
	}
	int small = parr[x];
	int proc = x;
	for(int i = x;i<n;i++){
		if(parr[i] < small && completed[i]!=1 && parrival[i] <= arrival){
			small = parr[i];
			proc = i;
		}
	}
	return proc;
} 
void pickproc(int parr[],int completed[],int n,int ptat[],int parrival[]){
	int flag = 0;
	int t = 0;
	while(flag!=5){
		int p = small(parr,n,parrival,completed,t);
		parr[p]-=1;
		t++;
		if(parr[p]==0){
			ptat[p] = t-parrival[p];
			flag++;
			completed[p]==1;
			cout << p << ": tat: " << ptat[p]; 
		}
	}
}
int main(){ 
	cout << "start";
	int parr[5] = {4,2,3,1,5};
	int parrival[5] = {7,0,8,2,1};
	int completed[5] = {0,0,0,0,0};
	int  ptat[5];
	int n = 5;
	order(parrival,parr,n);
	pickproc(parr,completed,n,ptat,parrival);
	return 0;
}

