#include<iostream>
using namespace std;
int count=0;
int findstring(char *str,char *substr){
    int i = 0, j = 0;
    count++;
    while ((*(str + j) != '\0')&&(*(substr + i) != '\0')) {
            count++;
        if (*(substr + i) != *(str + j)) {
            count++;
            j++;
            i = 0;
        }
        else {
            count++;
            i++;
            j++;
        }
    }
    count++;
    if (*(substr + i) == '\0')
        {
            count++;
            return 1;
        }
    else{
            count++;
        return -1;
    }

}


int main(){
    char str[40],substr[40];
    cout<<"Enter the string";
   cin.getline(str,40);
    cout<<"Enter the substring";
    fflush(stdin);
   cin.getline(substr,40);
    cout<<" findstring():   \n" <<findstring(str,substr);
  cout<<"\n"<<"No of steps for the ->"<< n<<" -> elements is -> "<<count;
    return 0;
}
