// Program to find Transpose of a matrix using Sparse Row Method
#include <iostream>
using namespace std;
class Sparse
{
public:
    int row;
    int column;
    int value;
    void set(int r, int c, int v)
    {
        row = r;
        column = c;
        value = v;
    }
    void display()
    {
        cout << row << ' ' << column << ' ' << value << endl;
    }
    
    static Sparse* slowtranspose(Sparse *);
    static Sparse* fasttranspose(Sparse *);
    
    
};
Sparse*  Sparse::slowtranspose(Sparse a[])
{
    static Sparse b[100];
    int ctr = 1, pass, obj;
    for (pass = 0; pass < a[0].column; pass++)
    {
        for (obj = 0; obj <= a[0].value; obj++)
        {
            if (a[obj].column == pass)
            {
                b[ctr].column = a[obj].row;
                b[ctr].row = a[obj].column;
                b[ctr].value = a[obj].value;
                ctr++;
            }
        }
    }
    b[0].row = a[0].column;
    b[0].column = a[0].row;
    b[0].value = a[0].value;
    return b;
}
Sparse*  Sparse::fasttranspose(Sparse a[])
{
    static Sparse b[100];
    int rowterm[20],startpos[20],i;
    for (i = 0; i < a[0].column; i++)
    {
       rowterm[i]=0;
    }
    for (i = 1; i <= a[0].value; i++)
    {
       rowterm[a[i].column]++;
    }
    startpos[0]=1;
    for (i = 1; i < a[0].column; i++)
    {
       startpos[i]=startpos[i-1]+rowterm[i-1];
    }
    
    b[0].row = a[0].column;
    b[0].column = a[0].row;
    b[0].value = a[0].value;
    int b_i;

    for (i = 1; i <= a[0].value; i++)
    {
       b_i=startpos[a[i].column];
       b[b_i].column=a[i].row;
       b[b_i].row=a[i].column;
       b[b_i].value=a[i].value;
       startpos[a[i].column]++;

    }
    return b;
}

int main()
{
    int m, n;
    cout << "Enter the size of the matrix:" << endl;
    cin >> m >> n;
    int arr[m][n];
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter [" << i << "][" << j << "]:";
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                count++;
        }
    }
    // Developing a sparse matrix
    Sparse s[count + 1];
    s[0].set(m, n, count);
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                s[++k].set(i, j, arr[i][j]);
            }
        }
    }
    cout << "Matrix before Transposing" << endl;
    for (int k = 0; k <= count; k++)
    {
        s[k].display();
    }

    Sparse *b=Sparse::slowtranspose(s);
    cout << "Matrix after Transposing" << endl;
    for (int k = 0; k <= count; k++)
    {
        b[k].display();
    }
    cout<<"\n"<<"Using Fast Transpose";
    Sparse *c=Sparse::fasttranspose(s);
    cout << "Matrix after Transposing" << endl;
    for (int k = 0; k <= count; k++)
    {
        c[k].display();
    }
}