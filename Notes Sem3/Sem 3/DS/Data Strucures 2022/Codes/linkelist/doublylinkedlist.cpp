#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* insertAtHead(int data,Node* root){
    Node*temp=new Node(data);
    temp->next=root;
    root=temp;
    return root;
}
Node* insertAtTail(int data,Node* root){
    if(root==NULL){
        Node*root=new Node(data);
        return root;
    }
    Node* cur=root;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    Node* temp=new Node(data);
    cur->next=temp;
    return root;
}
void printll(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL";
}
int main(){
    Node*root=NULL;
    root=insertAtTail(3,root);
    root=insertAtTail(4,root);
    root=insertAtTail(5,root);
    root=insertAtHead(2,root);
    printll(root);
    return 0;
}