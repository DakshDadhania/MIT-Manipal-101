#include<iostream>
using namespace std;
#define max_size 40
class queue{
    private:
    int front=-1,rear=-1;
    char q[max_size];
    public:
    void insert(char ele){
        if((rear+1)%max_size==front){
            cout<<"q full\n";
            return;
        }
        if(front==-1 && rear==-1){
            cout<<"Empt q\n";
        }
        rear=(rear+1)%max_size;
        q[rear]=ele;
    }
    int del(){
        if(front==-1 && rear==-1){
            cout<<"Empt q\n";
        }
        int ele=q[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%max_size;
            return ele;
        }
    }
    void display(){
        int i;
        for( i=front;i!=rear;i=((i+1)%max_size)){
            cout<<q[i]<<' ';
        }
        cout<<q[i]<<endl;
    
    }

};

int main(){
    return 0;
}