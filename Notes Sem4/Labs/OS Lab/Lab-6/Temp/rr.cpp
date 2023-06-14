#include <iostream>
using namespace std;
int t,prev1;
int pickproc(int parr[],int parrival[],int n){
	bool flag = true;
	while(flag == true){
		if(parr[prev1]!=0 && parrival[prev1]<=t){
			flag = false;
			int temp = prev1;
			prev1=(prev1+1)%n;
			return temp;		
		}else{
			prev1=(prev1+1)%n;
		}
	}
	return 0;
}
void rr(int parr[],int parrival[],int n,int q){
	int flag = 0;
	while(flag < n){
		int p = pickproc(parr,parrival,n);
		if(parr[p]<=q){
			t = t+parr[p];
			flag++;
			parr[p]=0;
			cout <<"proc :" << p <<" tat: " << t-parrival[p]<<endl;
		}else{
			t=t+q;
			parr[p]= parr[p]-q;
		}
	}
}
int main(){ 
	cout << "start\n";
	int parr[5] = {8,4,9,5,10};
	int parrival[5] = {0,1,2,3,4};
	int  ptat[5];
	int n = 5;
	prev1 = 0;
	t = 0;
	int q = 4;
	rr(parr,parrival,n,q);
	return 0;
}

