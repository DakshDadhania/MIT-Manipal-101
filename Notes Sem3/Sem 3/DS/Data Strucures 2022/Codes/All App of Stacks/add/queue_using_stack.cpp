#include<bits/stdc++.h>
using namespace std;
class Stack {
public: 
    int top;
    int arr[40];
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top==40-1){
            return true;
        }
        return false;
    }
    void push(int l){
        if(!isFull()){
            arr[++top]=l;
        }
        else{
            cout<<"Stack is full";
        }
    }
    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack empty";
            return -999;
        }
    }
    int peek(){
         if(!isEmpty()){
            return arr[top];
        }
        else{
            cout<<"Stack empty";
            return -999;
        }
    }
    void display(){
        if(!isEmpty()){
            for(int i=top;i>-1;i--){
                cout<<arr[i];
            }
        }
        else{
            cout<<"Stack empty";
        }
    }

    

Stack(){
    top=-1;
}


};
class Queue{
    Stack s1, s2;
 public:
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.isEmpty()) {
            s2.push(s1.peek());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.isEmpty()) {
            s1.push(s2.peek());
            s2.pop();
        }
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.isEmpty()) {
            cout << "Q is Empty";
            exit(0);
        }
 
        // Return top of s1
        int x = s1.peek();
        s1.pop();
        return x;
    }
    void display(){
        // Stack s3=s1;
        if(s1.isEmpty()){
            cout<<"Queue empty";
            return;
        }
        s1.display();

        
    }
};


int main(){
    Queue q1;
     int d,i,j;
    do
    {
        cout<<"Enter the task you wish to perform\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit"<<endl;
        cin>>d;
        switch(d)
        {
        case 0:
            break;
        case 1:
            {
                cout<<"enter element to push"<<endl;
                cin>>j;
                q1.enQueue(j);
                break;
            }
        case 2:
            {
                cout<<q1.deQueue()<<'\n';
                break;
            }
        case 3:
            {
                q1.display();
                cout<<'\n';
            }
        }
    }while(d!=0);
    
    return 0;

}