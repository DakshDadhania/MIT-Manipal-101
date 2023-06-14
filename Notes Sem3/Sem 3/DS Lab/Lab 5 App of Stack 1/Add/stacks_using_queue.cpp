#include<iostream>
#define max_size 40
using namespace std;

class queue{
    int front,rear;
    int q[max_size];
    public:
    void insert(int item){
        if(rear==max_size-1){
            cout<<"Queue Overflow  \n";
            return;
        }
        rear+=1;
        q[rear]=item;
    }
    int frontele(){
        if(front>rear)
            return -99;
        return q[front];
    }
    int size(){
        if(!isEmpty()){
            return ((rear-front)+1);
        }
        return 0;

    }
    int del(){
        if(front>rear)
            return -99;
        return q[front++];
    }
    void display(){
        int i;
        if(front>rear){
            cout<<"Empty array\n";
            return;
        }
        // cout<<"Contents: ";
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<" ";
        }
    }
     bool isEmpty(){
        if(front>rear){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear==max_size-1){
            return true;
        }
        return false;
    }
    queue(){
        front=0;
        rear=-1;

    }

};
class Stack {
    // Two inbuilt queues
    queue q1, q2;
 
public:
    void push(int x)
    {
        // Push x first in empty q2
        q2.insert(x);
 
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.isEmpty()) {
            q2.insert(q1.frontele());
            q1.del();
        }
 
        // swap the names of two queues
        queue q = q1;
        q1 = q2;
        q2 = q;
    }
 
    int pop()
    {
        // if no elements are there in q1
        if (q1.isEmpty())
            return -999;
        return q1.del();
    }
 
    int top()
    {
        if (q1.isEmpty())
            return -1;
        return q1.frontele();
    }
 
    int size() { 
        return q1.size(); 
        }
    int display(){

        q1.display();
    }
};
int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<" "<<s1.pop();
    s1.display();
    s1.push(4);
    s1.display();
    return 0;
}