#include<iostream>
using namespace std;
int findstring(char *str,char *substr){
    int i = 0, j = 0;
    while ((*(str + j) != '\0')&&(*(substr + i) != '\0')) {
        if (*(substr + i) != *(str + j)) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (*(substr + i) == '\0')
        return 1;
    else
        return -1;
}


int main(){
    char str[40],substr[40];
    cout<<"Enter the string";
   cin.getline(str,40);
    cout<<"Enter the substring";
    fflush(stdin);
   cin.getline(substr,40);
    cout<<" findstring():   \n" <<findstring(str,substr);

    return 0;
}
