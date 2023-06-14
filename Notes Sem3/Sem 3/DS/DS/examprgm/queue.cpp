#include<iostream>
using namespace std;
#define max_size 30
class queue{
    private:
    int rear,front;
    char q[100];
    public:
    queue(){
        front=0;
        rear=-1;
    }
    void insert(char ele){
        if(rear==max_size-1){
            cout<<"queue full";
        }
        else{
            q[++rear]=ele;
        }
    }
    int dele(){
        if(front>rear){
            cout<<"Queue empty";
            return;
        }
        return q[front++];
    }
    int display(){
        if(front>rear){
            cout<<"queue empty";
            return;
        }
        cout<<"Contents:";
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<" ";
        }
    }
};

int main(){

    return 0;
}