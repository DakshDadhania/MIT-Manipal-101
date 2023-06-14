#include<iostream>
#include<conio.h>

using namespace std;

void radixsort(int a[], int a1[], int n)
{
 int k, i, min, t,temp;
 for(k=0;k<3;k++)
 {
  for(i=0;i<n;i++)
  {
   min=a[i]%10;
   t=i;
   for(int j=i+1;j<n;j++)
   {
    if(min>(a[j]%10))
    {
     min=a[j]%10;
     t=j;
    }
   }
   temp=a1[t];
   a1[t]=a1[i];
   a1[i]=temp;

   temp=a[t];
   a[t]=a[i];
   a[i]=temp;
  }
  for(int j=0;j<n;j++)
     a[j]=a[j]/10;
 }
 cout<<"Sorted array:  ";
 for(i=0;i<n;i++)
    cout<<a1[i]<<"   ";
}

int main()
{
 int a[20],a1[20],n;
 cout<<"Enter the number of elements:";
 cin>>n;
 cout<<"Enter the elements:";
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
   a1[i]=a[i];
 }
 cout<<"Calling radix sort:";
 getch();
 radixsort(a,a1,n);
 //getch();
 return 0;
}
