// CPP program to find infix for
// a given postfix.
#include <bits/stdc++.h>
using namespace std;
class Stack {
public: 
    int top;
    string arr[40];
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
    void push(string l){
        if(!isFull()){
            arr[++top]=l;
        }
        else{
            cout<<"Stack is full";
        }
    }
    string pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            cout<<"Stack empty";
            return "-999";
        }
    }
    string peek(){
         if(!isEmpty()){
            return arr[top];
        }
        else{
            cout<<"Stack empty";
            return "-999";
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
bool isOperand(char x)
{
return (x >= 'a' && x <= 'z') ||
		(x >= 'A' && x <= 'Z');
}

// Get Infix for a given postfix
// expression
string getInfix(string exp)
{
	Stack s;

	for (int i=0; exp[i]!='\0'; i++)
	{
		// Push operands
		if (isOperand(exp[i]))
		{
		string op(1,exp[i]);
		s.push(op);
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			string op1 = s.pop();
			
			string op2 = s.pop();
			s.push("(" + op2 + exp[i] +
				op1 + ")");
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.peek();
}

// Driver code
int main()
{
	string exp = "abc/-ak/l-*";
	cout << getInfix(exp);
	return 0;
}
