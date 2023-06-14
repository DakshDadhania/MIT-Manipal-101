#include<stdio.h>

int main(void)
{
    int matrix[3][3] = {12,21,34,11,45,53,67,13,76};
    int r=3,c=3;
    for (int i=0;i<c;i++){
        for( int j=0;j<r;j++){
            if (i+1==j)
                printf("%d\t",matrix[j][i]);
        }
    }
    return 0;
}