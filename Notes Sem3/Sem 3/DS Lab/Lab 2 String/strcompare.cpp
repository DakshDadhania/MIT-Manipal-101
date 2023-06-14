#include<iostream>
#include "stdio.h"
using namespace std;
int strlenn(char str[]){
    int Countt=0;
    for(int i=0;str[i]!='\0';i++){

            Countt++;

    }
    return Countt;
}
bool strcomp(char s1[],char s2[]){
    int l1=strlenn(s1);
    int l2=strlenn(s2);
    int Count=0;
    if(l1==l2){
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]==s2[i]){
            Count++;
        }
    }

    if(Count==l1){
        return true;
    }
    }
    return false;
}
int main(){
    char s1[100],s2[100],s3[100];
    int n;
    cout<<"Enter substring 1  ";
    gets(s1);
   
    cout<<"Enter substring 2  ";
    gets(s2);
    strcomp(s1,s2)?cout<<"yes same":cout<<"no";

    return 0;

}
