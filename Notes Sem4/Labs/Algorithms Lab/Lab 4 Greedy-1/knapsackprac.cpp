#include<iostream>

using namespace std;
void knapsack(int n,int cap,int *w,int *p,int *pos){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j]/w[j]<p[j+1]/w[j+1]){
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                temp=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=temp;

            }   

        }

    }
    int profit=0;
    int i=0;
    while(cap>0){
        if(cap>=w[i]){
            profit+=p[i];
            cap-=w[i];
            cout<<"Item "<<pos[i]+1<<" is selected"<<endl;
        }
        else{
            profit+=cap*p[i]/w[i];
            cout<<"Item "<<pos[i]+1<<" is selected partially"<<endl;
            cap=0;
        }
        i++;
    }

}

int main(){
    cout<<"Enter the size of knapsack";
    int cap;cin>>cap;
    cout<<"Enter the no of items";
    int n;cin>>n;
    int w[n],p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the weight and profit of item "<<i+1<<endl;
        cin>>w[i]>>p[i];
    }
    int pos[n];
    for(int i=0;i<n;i++){
        pos[i]=i;
    }
    knapsack(n,cap,w,p,pos);

}
