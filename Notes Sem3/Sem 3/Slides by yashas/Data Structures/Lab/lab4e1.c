#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define MaxSize 10
typedef struct{
    char stack[MaxSize];
    int top;
}STACK;

void Push(STACK *s,char item){
    if (s->top==MaxSize-1)
    {
        printf("Stack Overflow");
        return;
    }
    s->stack[++(s->top)]=item;
}
char Pop(STACK *s)
{
    return (s->stack[(s->top)--]);
}

int isp(char x){
    switch(x){
        case '^': return 4; //right associative - higher value than icp(^) so as to
                            //pop ^
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case ')': return 0;
        case '#': return -1;
    }

}
int icp(char x){
    switch(x){
        case ')': return 5;
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }
}
void infix_prefix(char infix[], char prefix[])
{
    STACK *s, s1;
    int i=0,j=0;
    char x,y;

    s=&s1;
    s->top=-1;
    strrev(infix);
    Push(s,'#');
    for(x=infix[i];x!='\0'; i++,x=infix[i]){
        if (isdigit(x)){
            prefix[j++]=x;
        }
        else
            if (x =='(')
            {
                y = Pop(s);
                while(y!=')'){
                    prefix[j++]=y;
                    y = Pop(s);
                }
            }
            else{
                    y=Pop(s);
                    while(isp(y)>icp(x)){ // only > to achieve
                    //proper conversion for left associative operators
                        prefix[j++]= y;
                        y = Pop(s);
                    }


                    Push(s,y); //last operator that is popped
                    Push(s,x); //incoming operator
                }

        }

        y=Pop(s); //pop until eos

        while(y!='#'){
            prefix[j++]= y;
            y = Pop(s);

        }

        prefix[j]='\0';
        strrev(prefix);
}
int main()
{
        char infix[10],prefix[10];

        printf("Enter an infix expression :");
        scanf("%s",infix);

        infix_prefix(infix,prefix);
        printf("Prefix = %s",prefix);
        return 0;
}


