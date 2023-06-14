#include<iostream>
#include "stdio.h"
#include<string.h>
using namespace std;


int main(){
    char str[50];
    gets(str);
    char a[30][30];
    int i=0,j=0,k=0;

    for(i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            a[j][k]='\0';
            j++;
            k=0;
        }
        else{
            a[j][k++]=str[i];
        }


    }
    a[j][k]='\0';
    for(i=0;i<j+1;i++){
        for(k=strlen(a[i])-1;k>=0;k--){
            cout<<a[i][k];
        }
        cout<<' ';
    }


    return 0;
}
