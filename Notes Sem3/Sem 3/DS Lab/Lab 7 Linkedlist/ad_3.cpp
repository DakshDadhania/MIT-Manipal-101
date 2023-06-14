#include<iostream>
#include <stdlib.h>
using namespace std;
class list{
public:
    int val;
    list* next;
};

list* createList(){
    list *temp=new list;
    cout<<">";
    int n;
    cin>>n;
    if(n==-1){
        return NULL;
    }
    else{
        temp->val=n;
        temp->next=createList();
        return temp;
    }
}
void print(list *h)
{
    cout<<h->val<<" ";
    if(h->next!=NULL){
        print(h->next);
    }
    return;
}


list* mergealt(list *a, list *b){
    list *temp;
    if(a==NULL&&b==NULL){
        return NULL;
    }
    else if(a==NULL)
    {
        return b;
    }
    else if(b==NULL){
        return a;
    }
    else{
        temp=a;
        temp->next=mergealt(b,a->next);
    }
    
    return temp;
    
}
int main()
    {

    list *l1,*l2,*l3;
    cout<<"Enter values(-1 to stop) for list 1: ";
    l1=createList();
    print(l1);
    cout<<"Enter values(-1 to stop) for list 2: ";
    l2=createList();
    print(l2);
    l3=mergealt(l1,l2);
    cout<<"The merged list is: ";
    print(l3);
}