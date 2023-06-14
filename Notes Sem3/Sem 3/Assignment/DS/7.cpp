#include <iostream>
using namespace std;
class sparse_matrix
{
 
    // Maximum number of elements in matrix
    const static int MAX = 100;
    int **data;
    int row, col;
    int len;
 
public:
    sparse_matrix(int r, int c)
    {
        row = r;
        col = c;
        len = 0;
        data = new int *[MAX];
 
        // Array representation
        // of sparse matrix
        //[,0] represents row
        //[,1] represents col
        //[,2] represents value
        for (int i = 0; i < MAX; i++)
            data[i] = new int[3];
    }
 
    
    void insert(int r, int c, int val)
    {
        if (r > row || c > col)
        {
            cout << "Wrong entry";
        }
        else
        {
            data[len][0] = r;
            data[len][1] = c;
            data[len][2] = val;
            len++;
        }
    }
 
    int getByRow(sparse_matrix b,int r,int c)
    {
        for(int i=0;i<=b.data[0][2];i++){
            if(r==b.data[i][0] && c==b.data[i][1]){
                return b.data[i][2];
            }
        }
        return -1;
          
    }
    int getNumElementsInColumn( sparse_matrix b,int value){
        int colcount=0;
        for(int i=0;i<=b.data[0][2];i++){
            if(value==b.data[i][1]){
                colcount++;
            }
        }
        return colcount;
    }
    
 
    // printing matrix
    void print()
    {
        cout << "\nDimension: " << row << "x" << col;
        cout << "\nSparse Matrix: \nRow\tColumn\tValue\n";
 
        for (int i = 0; i < len; i++)
        {
            cout << data[i][0] << "\t " << data[i][1]
                 << "\t " << data[i][2] << endl;
        }
    }
};
int main()
{
    int row_size=0,col_size=0;
    cout<<"Enter row size";
    cin>>row_size;
    cout<<"Enter col size";
    cin>>col_size;
	sparse_matrix a(row_size, col_size);
    
	int sparseMatrix1[row_size][col_size] ={0};
    
	int size1 = 0,size2=0;
    for (int i = 0; i < row_size; i++)
		for (int j = 0; j < col_size; j++)
			{
                cout<<"Enter Matrix element at ROW: ["<<i<<"] COLUMN: ["<<j<<"]";
                cin>>sparseMatrix1[i][j];
            }
	for (int i = 0; i < row_size; i++)
		for (int j = 0; j < col_size; j++)
			if (sparseMatrix1[i][j] != 0)
				size1++;

	
	int compactMatrix[size1+1][3];
    compactMatrix[0][0]=row_size;
    compactMatrix[0][1]=col_size;
    compactMatrix[0][2]=size1;
	int k = 1;
	for (int i = 0; i < row_size; i++)
		{
            for (int j = 0; j < col_size; j++)
                {
                    if (sparseMatrix1[i][j] != 0)
                    {
                        compactMatrix[k][0] = i;
                        compactMatrix[k][1] = j;
                        compactMatrix[k][2] = sparseMatrix1[i][j];
                        k++;
                        a.insert(i,j,sparseMatrix1[i][j]);
                    }
                }
        }

    for (int i = 0; i < row_size; i++)
		{for (int j = 0; j < col_size; j++)
			{
                cout<<sparseMatrix1[i][j]<<" ";
               
            }
        cout<<"\n";
        }
	for (int i=0; i<size1+1; i++)
	{
		for (int j=0; j<3; j++)
			cout <<" "<< compactMatrix[i][j];

		cout <<"\n";
	}
    cout<<"Element at the specified row and column :"<<a.getByRow(a,2,2)<<'\n';
    cout<<"Total no of elements in the given column :"<<a.getNumElementsInColumn(a,3);
   
	return 0;
}

