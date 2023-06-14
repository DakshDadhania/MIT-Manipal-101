#include<iostream>
#include<math.h>

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

int prefixeval(string s){
    Stack stk;
    
    
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9'){
            stk.push(s[i]-'0');
        }
        else{
            int a=stk.pop();
            
            int b=stk.pop();
            
            switch(s[i]){ 
                case '+':    
                    stk.push(a+b);
                    break;
                case '-':    
                    stk.push(a-b);
                    break;
                case '*':    
                    stk.push(a*b);
                    break;
                case '/':    
                    stk.push(a/b);
                    break;
                case '^':    
                    stk.push(pow(a,b));
                    break;
            }

        }
        
    }
    return stk.pop();

}

//Prefix Evaluation is done from last to first
int main(){
    cout<<"This is prefix evaluation calculator.. Enter the prefix expression";
    string s;
    cin>>s;

    cout<<"Final value : "<<prefixeval(s);


    return 0;

}
//-+7*45+20