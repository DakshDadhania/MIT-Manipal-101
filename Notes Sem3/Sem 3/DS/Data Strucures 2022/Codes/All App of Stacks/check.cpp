#include<iostream>
using namespace std;
string reverse(string s){
    int j=0;
    string ans="                                      ";
    for(int i=s.length();i>=0;i--){
        if(s[i]=='('){
            ans[j++]=')';
        }
        else if(s[i]==')'){
            ans[j++]='(';
        }
        else{
            ans[j++]=s[i];
        }
    }
    return ans;
}
int main(){
    string are="hskad";
    string name=reverse(are);
    cout<<name;
    return 0;

}