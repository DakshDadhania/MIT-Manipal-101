// CPP Program to convert prefix to postfix
#include <iostream>
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
// function to check if character is operator or not
bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

	Stack s;
	// length of expression
	int length = pre_exp.size();

	// reading from right to left
	for (int i = length - 1; i >= 0; i--)
	{
		// check if symbol is operator
		if (isOperator(pre_exp[i]))
		{
			// pop two operands from stack
			string op1 = s.pop();
			string op2 =s.pop();
			

			// concat the operands and operator
			string temp = op1 + op2 + pre_exp[i];

			// Push string temp back to stack
			s.push(temp);
		}

		// if symbol is an operand
		else {

			// push the operand to the stack
			s.push(string(1, pre_exp[i]));
		}
	}

	// stack contains only the Postfix expression
	return s.peek();
}

// Driver Code
int main()
{
	string pre_exp = "*-A/BC-/AKL";
	cout << "Postfix : " << preToPost(pre_exp);
	return 0;
}
