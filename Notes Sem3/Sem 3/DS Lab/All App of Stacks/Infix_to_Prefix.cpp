
#include <bits/stdc++.h>
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
            return 'N';
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
bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	Stack char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		// If the scanned character is an
		// operand, add it to output.
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (infix[i] == '(')
			char_stack.push('(');

		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (infix[i] == ')') {
			while (char_stack.peek() != '(') {
				output += char_stack.peek();
				char_stack.pop();
			}

			// Remove '(' from the stack
			char_stack.pop();
		}

		// Operator found
		else
		{
			if (isOperator(char_stack.peek()))
			{
				if(infix[i] == '^')
				{
					while (getPriority(infix[i]) <= getPriority(char_stack.peek()))
					{
						output += char_stack.peek();
						char_stack.pop();
					}
					
				}
				else
				{
					while (getPriority(infix[i]) < getPriority(char_stack.peek()))
					{
						output += char_stack.peek();
						char_stack.pop();
					}
					
				}

				// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	while(!char_stack.isEmpty()){
		output += char_stack.peek();
		char_stack.pop();
	}
	return output;
}

string infixToPrefix(string infix)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = infix.size();

	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

// Driver code
int main()
{
	string s = ("(((a*b)/((c-d)*e))*f)");
	cout << infixToPrefix(s) << std::endl;
	return 0;
}
