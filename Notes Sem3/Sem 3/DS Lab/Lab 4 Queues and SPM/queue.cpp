#include<iostream>
#define max_size 30
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
    int del(){
        if(front>rear)
            return -1;
        return q[front++];
    }
    void display(){
        int i;
        if(front>rear){
            cout<<"Empty array\n";
            return;
        }
        cout<<"Contents: ";
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<" ";
        }
    }
    queue(){
        front=0;
        rear=-1;

    }

};
int main(){
    queue q;
    int ans=0;
    
    cout<<"Welcome to menu driven queue || Enter 1 to enter || 2 to delete last element || 3 to display || Enter -999 to exit";
    while(ans!=-999){    
        
        cin>>ans;
        cout<<"\n";
        if(ans==1){
        
            int i;
            
                cout<<"Enter the element";
                int c=0;
                cin>>c;
                q.insert(c);
            
        }
        else if(ans==2){
       
            cout<<q.del()<<" deleted\n";
        
        }
        else if(ans==3) 
            { 
                q.display();
                cout<<"\n";
            }
        cout<<"\nEnter 1 to enter || 2 to delete last element || 3 to display || Enter -999 to exit";
        }
    return 0;
}
