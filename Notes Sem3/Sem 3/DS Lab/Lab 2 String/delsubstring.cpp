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
    char s1[100],s2[100],s3[10][100],s4[10][100];
    int n;

    fflush(stdin);
    cout<<"Enter string 1  ";
    gets(s1);
    fflush(stdin);
    cout<<"Enter substring 2  ";
    gets(s2);
    int j=0;
    int k=0;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]==' '){
            j++;
            k=0;
        }
        else{
            s3[j][k++]=s1[i];
        }
    }
    int k=0;
    for(int i=0;s2[i]!='\0';i++){
        if(s2[i]==' '){
            j++;
            k=0;
        }
        else{
            s4[j][k++]=s2[i];
        }
    }
    for(int i=0;i<j;i++){
        for(int j=0;j<strlen(s3[i]);j++){
            cout<<s3[i][j]<<"  ";
        }
        cout<<"\n";
    }
     for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<s4[i][j]<<"  ";
        }
         cout<<"\n";
    }


    return 0;

}

