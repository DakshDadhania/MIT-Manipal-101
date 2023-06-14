#include<iostream>
using namespace std;
int repadd(int x, int y)
{

    if (x < y)
        return repadd(y, x);


    else if (y != 0)
        return (x + repadd(x, y - 1));


    else
        return 0;
}
int main(){
    int n,a,b;
    cout<<"enter 2 nos to be multiplied";
    cin>>a>>b;
    n=repadd(a,b);
    cout<<"ans of a*b is: "<<n;
    return 0;

}
