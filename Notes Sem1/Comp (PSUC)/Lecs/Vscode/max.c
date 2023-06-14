#include<stdio.h>

int main()
{
    int a=2;
    int b=3;
    int c=5;
    int max;



    max= (a>b)? ((a>c)?a:c): ((b>c)?b:c);
    printf("%d \n",max);

    return 0;
}