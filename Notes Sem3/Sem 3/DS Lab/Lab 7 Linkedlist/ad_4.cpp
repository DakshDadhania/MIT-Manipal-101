// Program to implement Stacks and Queues using Singly Linked List
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
};

class Stack{
    private:
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=top;
        top=temp;
    }

    int pop(){
        if(top==NULL){
            cout<<"Empty Stack!"<<endl;
            return 0;
        }
        Node *trav=top;
        int elem;
        elem=top->data;
        top=top->next;
        delete trav;
        return elem;
    }

    int peek(){
        if(top==NULL){
            cout<<"Empty Stack!"<<endl;
            return 0;
        }
        return top->data;
    }

    void display(){
        Node *trav= top;
        cout<<"top->";
        while(trav){
            cout<<trav->data<<" ";
            trav=trav->next;
        }
    }
};

class Queue{
    private:
    Node *front, *rear;
    public:
    Queue(){
        front=rear=NULL;
    }

    void enqueue(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=NULL;
        if(!front){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
        return;
    }

    int dequeue(){
        if(!front){
            return 0;
        }
        Node *trav=front;
        int elem=trav->data;
        front=trav->next;
        if(front==NULL)
            rear=NULL;
        delete trav;
        return elem;
    }

    void display(){
        Node *trav= front;
        cout<<"front->";
        while(trav){
            cout<<trav->data<<" ";
            trav=trav->next;
        }
        cout<<"<-rear"<<endl;
        // cout<<"fv:"<<front<<" rv:"<<rear<<endl;
    }
};

int main(){
    Queue q;
    q.display();
    q.enqueue(100);
    q.display();
    q.enqueue(200);
    q.display();
    q.enqueue(300);
    q.display();
    q.enqueue(400);
    q.display();
    q.enqueue(500);
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(100);
    q.display();
    cout<<"\n\n\n";

    Stack stk;
    stk.push(20);
    stk.display();
    stk.push(30);
    stk.display();
    stk.push(50);
    stk.display();
    stk.pop();
    stk.display();
    stk.push(40);
    stk.push(50);
    stk.peek();
    stk.display();
}