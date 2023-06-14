#include<bits/stdc++.h>
using namespace std;

class Stack {
public: 
    int top;
    char arr[40];
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
    void push(char l){
        if(!isFull()){
            arr[++top]=l;
        }
        else{
            cout<<"Stack is full";
        }
    }
    char pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack empty";
            return 'N' ;
        }
    }
    char peek(){
         if(!isEmpty()){
            return arr[top];
        }
        else{
            cout<<"Stack empty";
            return 'N';
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
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else {
        return -1;
    }
}
string infixtopost(string s){
    Stack stk;
    string rs;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            rs+=s[i];
        }
        else if(s[i]=='('){
            stk.push(s[i]);
        }
        else if(s[i]==')'){
            while(!stk.isEmpty() && stk.peek()!='('){
                rs+=stk.pop();
            }
            if(!stk.isEmpty()){
                stk.pop();
            }
        }
        else{
            while(!stk.isEmpty() && prec(stk.peek())>prec(s[i])){
                rs+=stk.pop();
                
            }
            stk.push(s[i]);
        }


    }
    while(!stk.isEmpty()){
        rs+=stk.pop();
    }
    return rs;
}


int main(){
    
    cout<<infixtopost("((A+B)-C*(D/E))+F");
    return 0;
}

//(a-b/c)*(a/k-l)