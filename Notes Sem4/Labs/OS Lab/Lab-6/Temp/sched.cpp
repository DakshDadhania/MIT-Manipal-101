#include <iostream>
using namespace std;
int t;
int pickproc(int parr[],int completed[],int n,int ptat[],int barr[]){
	int x = 0;
	while(completed[x] == 1){
		x++;
	}
	int small = parr[x];
	int proc = x;
	for(int i = x;i<n;i++){
		if(parr[i] < small && completed[i]!=1){
			small = parr[i];
			proc = i;
		}
	}
	completed[proc] = 1;
	t = t+barr[proc];
	ptat[proc] = t;
	return proc;
}
int main(){
	int parr[5] = {4,2,3,1,5};
	int barr[5] = {5,2,10,11,2};
	int completed[5] = {0,0,0,0,0};
	int  ptat[5];
	t = 0;
	int n = 5;
	for(int i = 0;i<n;i++){
		int p = pickproc(parr,completed,n,ptat,barr);
		cout << "proc :"<<p<<" tat :"<<ptat[p] << endl;
	}
	return 0;
}
