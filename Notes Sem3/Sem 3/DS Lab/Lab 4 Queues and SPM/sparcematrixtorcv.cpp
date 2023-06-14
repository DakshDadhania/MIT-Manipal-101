#include <iostream>
using namespace std;

int main()
{
    int row_size=0,col_size=0;
    cout<<"Enter row size";
    cin>>row_size;
    cout<<"Enter col size";
    cin>>col_size;
	
	int sparseMatrix[row_size][col_size] ={0};
	int size = 0;
    for (int i = 0; i < row_size; i++)
		for (int j = 0; j < col_size; j++)
			{
                cout<<"Enter Matrix["<<i<<"] ["<<j<<"]";
                cin>>sparseMatrix[i][j];
            }
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < col_size; j++)
			if (sparseMatrix[i][j] != 0)
				size++;

	
	int compactMatrix[size+1][3];
    compactMatrix[0][0]=row_size;
    compactMatrix[0][1]=col_size;
    compactMatrix[0][2]=size;
	int k = 1;
	for (int i = 0; i < row_size; i++)
		{
            for (int j = 0; j < col_size; j++)
                {
                    if (sparseMatrix[i][j] != 0)
                    {
                        compactMatrix[k][0] = i;
                        compactMatrix[k][1] = j;
                        compactMatrix[k][2] = sparseMatrix[i][j];
                        k++;
                    }
                }
        }
    for (int i = 0; i < row_size; i++)
		{for (int j = 0; j < col_size; j++)
			{
                cout<<sparseMatrix[i][j]<<" ";
               
            }
        cout<<"\n";
        }
	for (int i=0; i<size+1; i++)
	{
		for (int j=0; j<3; j++)
			cout <<" "<< compactMatrix[i][j];

		cout <<"\n";
	}
	return 0;
}

