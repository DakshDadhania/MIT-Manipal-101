#include<iostream>
using namespace std;

int f(int x, int *py, int **ppz)
{
    int y, z;
    cout<<x<<" 1 "<<y<<" "<<**ppz<<*py<<" \n";
    **ppz += 1;
    cout<<x<<" 2 "<<y<<" "<<**ppz<<*py<<" \n";
    z = **ppz;
    cout<<x<<" 3 "<<y<<" "<<z<<*py<<" \n";
    *py += 2;
    cout<<x<<" 4 "<<y<<" "<<z<<*py<<" \n";
    y = *py;
    cout<<x<<" 5 "<<y<<" "<<z<<" \n";
   
    return x + y + z;
}
int main()
{
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);
    return 0;
}
//OUTPUT
//19