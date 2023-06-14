#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print(int x[][10],int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%d\t",x[i][j]);
        }
    }	
}

int main(){
    int A[10][10],N[10][10],AV[10][10],pid,m;
    int i,j,k,x=0;
    int F[10],W[1][10];
    int pflag=0,flag=0;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the number of resources: ");
    scanf("%d",&m);
    printf("Enter the allocation matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the max matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&N[i][j]);
        }
    }
    printf("Enter the available matrix: ");
    for(i=0;i<m;i++){
        scanf("%d",&AV[0][i]);
    }
    for(i=0;i<n;i++)
        F[i]=0;
    for(i=0;i<m;i++)
        W[0][i]=AV[0][i];
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(F[i] == 0){
                flag=0;
                for(j=0;j<m;j++){
                    if(N[i][j] > W[0][j]){
                        flag=1;
                        break;
                    }
                }
                if(flag == 0 && F[i] == 0){
                    for(j=0;j<m;j++)
                        W[0][j]+=A[i][j];
                    F[i]=1;
                    pflag++;
                }
            }
        }
        if(pflag == n)
            return 1;
    }
    
    return 0;
}