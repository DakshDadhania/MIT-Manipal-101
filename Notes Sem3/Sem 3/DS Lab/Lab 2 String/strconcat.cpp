#include<iostream>
#include "stdio.h"
using namespace std;
int strlenn(char str[]){
    int Count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ')
            {
                continue;
                }
        else
            {
            Count++;
            }
    }
    return Count;
}
void strconcat(char s1[],char s2[]){
    int j=strlenn(s1)+1;

   for(int i=0;s2[i]!='\0';i++){
        s1[j++]=s2[i];
    }
    s1[j++]='\0';

}
int main(){
    char s1[100],s2[100],s3[100];
    int n;
    cout<<"Enter substring 1  ";
    gets(s1);
    fflush(stdin);
    cout<<"Enter substring 2  ";
    gets(s2);

    strconcat(s1,s2);
    puts(s1);

    return 0;

}

