#include <stdio.h>
#include <stdlib.h>
void copy(char a[],char b[],int count){
    b[count]=a[count];
    if(a[count]=='\0'){
        return;
    }
    copy(a,b,count++);
}
int main()
{
    char a[20],b[20];
    printf("Enter the string ");
    scanf("%s",a);
    copy(a,b,0);
    printf("The string obtained after copying is %s",b);
    return 0;
}