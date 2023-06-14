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
void insertAtHead(int data,Node* &root){
    Node*temp=new Node(data);
    temp->next=root;
    root=temp;
    return;
    // return root;
}
void insertAtTail(int data,Node* &root){
    if(root==NULL){
        root=new Node(data);
        return;
        // return root;
    }
    Node* cur=root;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    Node* temp=new Node(data);
    cur->next=temp;
    // return root;
}
void printll(Node* &root){
    Node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<"NULL";
}

void deletell(Node* &root,int val){
    Node* curr=root;
    if(curr->data==val){
        root=curr->next;
        return;
    }
    while(curr->next->data!=val){
        curr=curr->next;
    }
    curr->next=curr->next->next;

}
void insertMid(Node* &root,int mid,int val){
    Node* curr=root;
    Node* temp=new Node(val);
    if(mid==1){
        temp->next=curr;
        root=temp;
        return;
    }
    while(mid!=2){
        curr=curr->next;
        mid--;
    }
    temp->next=curr->next;
    curr->next=temp;


}
void replacebyno(Node* &root,int mid,int val){
    Node* curr=root;
    Node* temp=new Node(val);
    if(mid==1){
        temp->next=curr->next;
        root=temp;
        return;
    }
    while(mid!=2){
        curr=curr->next;
        mid--;
    }
    temp->next=curr->next->next;
    curr->next=temp;
}
Node* sort(Node* root){
    Node*cur=root;
    Node*temp=NULL;
    Node*min=NULL;
    while(cur!=NULL){
        min=cur;
        temp=cur->next;
        while(temp!=NULL){
            if(temp->data < min->data){
                min=temp;
            }
            temp=temp->next;
        }
            if(min!=cur){
                swap(min->data,cur->data);
            }
        
        cur=cur->next;
    }

    return root;
}
void reverse(Node* root){
    Node* prev=NULL,*next=NULL,*curr=root;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    root=prev;
}

void deletenol(Node* &root,int no){
    Node* curr=root;
    if(no==1){
        root=curr->next;
        return;
    }
    while(no!=2){
        curr=curr->next;
        no--;
    }
    curr->next=curr->next->next;

}

int main(){
    Node*root=NULL;
    insertAtTail(3,root);
    insertAtTail(4,root);
    insertAtTail(5,root);
    insertAtHead(2,root);
    insertAtTail(0,root);
    printll(root);
    cout<<endl;
    
    
    cout<<endl;
    cout<<endl;

    root=sort(root);
    
    printll(root);
    cout<<endl;

    return 0;
}