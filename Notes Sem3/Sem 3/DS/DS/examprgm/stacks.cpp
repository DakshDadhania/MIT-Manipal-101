#include<iostream>
#define max_size 30
using namespace std;
class stack{
private:
    int top;
    char a[100];
public:
stack(){
    top=-1;
}
    void push(char ele){
        if(top==max_size-1){
            cout<<"Stack overflow";
        }
        else{
            a[++top]=ele;}
    }
    int pop(){
        if(top==-1){
            cout<<"Stack empty";
            return -1;
        }
        return a[top--];
    }
    int peek(){
        if(top==-1){
            cout<<"Stack empty";
            return -1;
        }
        return a[top];
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout<<a[i]<<"\n";
        }
    }
    
};
int main(){
    return 0;
}