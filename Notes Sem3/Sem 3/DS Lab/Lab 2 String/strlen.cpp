#include<iostream>
#include "stdio.h"
using namespace std;
int strlenn(char str[]){
    int Count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ')
            continue;

        else
            Count++;
        }
    return Count;}
int main(){

    char str[100];
    cout << "Enter a string: \n";
    gets(str);
    fflush(stdin);
    cout << "You entered: " << str<<"\n";
    cout<<"Length of string : \n "<<strlenn(str);
    return 0;
}
