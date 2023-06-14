#include<iostream>
using namespace std;
class stk
{
public:
    int top=-1;
    int arr[500];
    bool isFull()
    {
        if(top==4)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    void push(int num)
    {
        if(!isFull())
        {
            top++;
            arr[top]=num;
        }
    }
    int pop()
    {
        if(!isEmpty())
        {
            return (arr[top--]);
        }
        return -333;
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
};
int main()
{
    stk s1,s2;
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
                s1.push(j);
                break;
            }
        case 2:
            {
                while(!s1.isEmpty())
                {
                    s2.push(s1.pop());
                }
                cout<<"Element is "<<s2.pop()<<endl;
                while(!s2.isEmpty())
                {
                    s1.push(s2.pop());
                }
                break;
            }
        case 3:
            {
                if(s1.isEmpty()){
                    cout<<"Queue empty";
                }
                s1.display();
                cout<<'\n';
            }
        }
    }while(d!=0);
}