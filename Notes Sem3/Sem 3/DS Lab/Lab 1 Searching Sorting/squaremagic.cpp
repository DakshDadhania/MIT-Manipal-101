#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the order of matrix";
    int n, a[10][10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                ans1 += a[i][j];
            if (i == n - j - 1)
            {
                ans2 += a[i][j];
            }
        }
    }
    
    if (ans1 == ans2)
    {
        int row[10]={0};
        int col[10]={0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                row[i] += a[i][j];

                col[j] += a[i][j];
            }
        }

        bool magic = true;
        for (int i = 0; i < n; i++)
        {   
            
            if (row[i] != ans1)
            {
                magic = false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (col[i] != ans1)
            {
                magic = false;
            }
        }

        if (magic == true)
        {
            cout << "Magic Matrix";
        }
        else
        {
            cout << "Not a magic matrix";
        }
    }
    else
    {
        cout << "Not a magic matrix";
    }

    return 0;
}