#include<iostream>
#include "stdio.h"
using namespace std;
int strlen(char str[]){
    int Count=0;
    for(int i=0;str[i]!='\0';i++){
        Count++;
    }
    return Count;
}
int main(){
    char s1[100],s2[100],s3[100];
    int posi;
    cout<<"Enter the index you want to place substring  ";
    cin>>posi;
    fflush(stdin);
    cout<<"Enter substring 1  ";
    gets(s1);
    fflush(stdin);
    cout<<"Enter substring 2  ";
    gets(s2);

    
    cout<<"string after adding substring  ";
    puts(s3);


    return 0;

}

