#include<iostream>
using namespace std;
void count(char* a){
    int vc=0,cc=0;
    while(*a!='\0'){
        
        if(*a=='A' ||*a=='E' ||*a=='I' ||*a=='O' ||*a=='U'
        		||*a=='a' ||*a=='e' ||*a=='i' ||*a=='o' ||*a=='u')
            vc++;    
        else if(*a!=' ')
            cc++;    
        a++;
    }
    cout<<"No of Vowels in String: "<<vc<<'\n';   
    cout<<"No of Consonants in String: "<<cc<<'\n';   
    
}
int main(){
    cout<<"Enter the string to count the no of Vowels and Consonants in the String :\n";
    char str[50];
    cin.getline(str,50);
    count(str);
    return 0;
}