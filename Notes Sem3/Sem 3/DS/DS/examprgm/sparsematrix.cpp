#include<iostream>
using namespace std;
class Sparse{
    public:
    int row,column,value;
    void display(){
        cout<< row<<" "<<column<<" "<<value<<"\n ";
    };
    static Sparse* slowtranspose(Sparse a[]){
        static Sparse b[100];
        int k=1;
        for(int i=0;i<a[0].column;i++){
            for(int j=0;j<=a[0].value;j++){
                if(a[j].column==i){
                    a[j].column=b[k].row;
                    a[j].row=b[k].column;
                    a[j].value=b[k].value;
                k++;
                }
            }
        }
        b[0].column=a[0].row;
        b[0].row=a[0].column;
        b[0].value=a[0].value;
        return b;

    }
    static Sparse* fasttranspose(Sparse a[]){
        static Sparse b[100];
        int rowterm[20],starpos[20],i;
        for(int i=0;i<a[0].column;i++){
            rowterm[i]=0;
        }
        for(int i=1;i<a[0].value;i++){
            rowterm[a[i].column]++;
        }
        starpos[0]=1;
        for(int i=1;i<a[0].column;i++){
            starpos[i]=starpos[i-1]+rowterm[i-1];
        }
        b[0].row=a[0].column;
        b[0].column=a[0].row;
        b[0].value=a[0].value;
        int b_i;
        for(int i=1;i<a[0].value;i++){
            b_i=starpos[a[i].column];
            b[b_i].column=a[i].row;
            b[b_i].row=a[i].column;
            b[b_i].value=a[i].value;

            starpos[a[i].column]++;
        }
        return b;
        

    }
};
int main(){
    int a[100][100];
    int row,column,count=0;
    cout<<"enter the row and column of matrix\n";
    cin>>row>>column;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<"Enter a["<<i<<"]["<<j<<"]\n";
            cin>>a[i][j];
            if(a[i][j]!=0){
                count++;
            }
        }
    }
    Sparse s[100];
    s[0].row=row;
    s[0].column=column;
    s[0].value=count;
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(a[i][j]!=0){
                s[k].row=i;
                s[k].column=j;
                s[k].value=a[i][j];
                k++;
            }

        }
    }
    cout<< "Row Column Value\n";
    cout<<row<<" "<<column<<" "<<count<<"\n";
    for(int i=1;i<k;i++){
        s[i].display();
    }
    Sparse::slowtranspose(s);
    return 0;
}