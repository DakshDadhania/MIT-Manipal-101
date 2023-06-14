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

    void add(sparse_matrix b)
    {
        if (row != b.row || col != b.col)
        {
            cout << "Matrices can't be added"; // IF MATRICES DONT HAVE SAME DIMENSIONS
        }

        else
        {
            int apos = 0, bpos = 0;
            sparse_matrix result(row, col);

            while (apos < len && bpos < b.len)
            {
                if (data[apos][0] > b.data[bpos][0] ||
                    (data[apos][0] == b.data[bpos][0] && // if b's row and col is smaller
                     data[apos][1] > b.data[bpos][1]))

                {
                    result.insert(b.data[bpos][0],
                                  b.data[bpos][1], // insert smaller value into result
                                  b.data[bpos][2]);

                    bpos++;
                }

                // if a's row and col is smaller
                else if (data[apos][0] < b.data[bpos][0] ||
                         (data[apos][0] == b.data[bpos][0] &&
                          data[apos][1] < b.data[bpos][1]))

                {

                    // insert smaller value into result
                    result.insert(data[apos][0],
                                  data[apos][1],
                                  data[apos][2]);

                    apos++;
                }

                else
                {

                    // add the values as row and col is same
                    int addedval = data[apos][2] +
                                   b.data[bpos][2];

                    if (addedval != 0)
                        result.insert(data[apos][0],
                                      data[apos][1],
                                      addedval);
                    // then insert
                    apos++;
                    bpos++;
                }
            }

            // insert remaining elements
            while (apos < len)
                result.insert(data[apos][0],
                              data[apos][1],
                              data[apos++][2]);

            while (bpos < b.len)
                result.insert(b.data[bpos][0],
                              b.data[bpos][1],
                              b.data[bpos++][2]);

            // print result
            result.print();
        }
    }
    sparse_matrix transpose2()
    {
        
        sparse_matrix b(col, row);
        int ctr = 0, pass, obj;
        for (pass = 0; pass < col; pass++)
        {
            for (obj = 0; obj <= len; obj++)
            {
                if (data[obj][1] == pass)
                {
                    b.data[ctr][1] = data[obj][0];
                    b.data[ctr][0] = data[obj][1];
                    b.data[ctr][2] = data[obj][2];
                    ctr++;
                }
            }
        }
       
        b.len = len;
        return b;
    }

    sparse_matrix transpose()
    {

        // new matrix with inversed row X col
        sparse_matrix result(col, row);

        // same number of elements
        result.len = len;

        // to count number of elements in each column
        int *rowterm = new int[col + 1];

        // initialize all to 0
        for (int i = 1; i <= col; i++)
            rowterm[i] = 0;

        for (int i = 0; i < len; i++)
            rowterm[data[i][1]]++;

        int *startpos = new int[col + 1];

        // to count number of elements having
        // col smaller than particular i

        // as there is no col with value < 0
        startpos[0] = 0;

        // initialize rest of the indices
        for (int i = 1; i <= col; i++)

            startpos[i] = startpos[i - 1] + rowterm[i - 1];

        for (int i = 0; i < len; i++)
        {

            // insert a data at rpos and
            // increment its value
            int rpos = startpos[data[i][1]]++;

            // transpose row=col
            result.data[rpos][0] = data[i][1];

            // transpose col=row
            result.data[rpos][1] = data[i][0];

            // same value
            result.data[rpos][2] = data[i][2];
        }

        // the above method ensures
        // sorting of transpose matrix
        // according to row-col value
        return result;
    }

    void multiply(sparse_matrix b)
    {
        if (col != b.row)
        {

            // Invalid multiplication
            cout << "Can't multiply, Invalid dimensions";
            return;
        }

        // transpose b to compare row
        // and col values and to add them at the end
        b = b.transpose();
        int apos, bpos;

        // result matrix of dimension row X b.col
        // however b has been transposed,
        // hence row X b.row
        sparse_matrix result(row, b.row);

        // iterate over all elements of A
        for (apos = 0; apos < len;)
        {

            // current row of result matrix
            int r = data[apos][0];

            // iterate over all elements of B
            for (bpos = 0; bpos < b.len;)
            {

                // current column of result matrix
                // data[,0] used as b is transposed
                int c = b.data[bpos][0];

                // temporary pointers created to add all
                // multiplied values to obtain current
                // element of result matrix
                int tempa = apos;
                int tempb = bpos;

                int sum = 0;

                // iterate over all elements with
                // same row and col value
                // to calculate result[r]
                while (tempa < len && data[tempa][0] == r &&
                       tempb < b.len && b.data[tempb][0] == c)
                {
                    if (data[tempa][1] < b.data[tempb][1])

                        // skip a
                        tempa++;

                    else if (data[tempa][1] > b.data[tempb][1])

                        // skip b
                        tempb++;
                    else

                        // same col, so multiply and increment
                        sum += data[tempa++][2] *
                               b.data[tempb++][2];
                }

                // insert sum obtained in result[r]
                // if its not equal to 0
                if (sum != 0)
                    result.insert(r, c, sum);

                while (bpos < b.len &&
                       b.data[bpos][0] == c)

                    // jump to next column
                    bpos++;
            }
            while (apos < len && data[apos][0] == r)

                // jump to next row
                apos++;
        }
        result.print();
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
    int row_size = 0, col_size = 0;
    cout << "Enter row size";
    cin >> row_size;
    cout << "Enter col size";
    cin >> col_size;
    sparse_matrix a(row_size, col_size);
    sparse_matrix b(row_size, col_size);
    int sparseMatrix1[row_size][col_size] = {0};
    int sparseMatrix2[row_size][col_size] = {0};
    int size1 = 0, size2 = 0;
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
        {
            cout << "Enter Matrix element at ROW: [" << i << "] COLUMN: [" << j << "]";
            cin >> sparseMatrix1[i][j];
        }
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
            if (sparseMatrix1[i][j] != 0)
                size1++;

    int compactMatrix[size1 + 1][3];
    compactMatrix[0][0] = row_size;
    compactMatrix[0][1] = col_size;
    compactMatrix[0][2] = size1;
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
                a.insert(i, j, sparseMatrix1[i][j]);
            }
        }
    }

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << sparseMatrix1[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < size1 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << " " << compactMatrix[i][j];

        cout << "\n";
    }
    cout << "\n\n Here starts Matrix 2";
    // matrix2
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
        {
            cout << "Enter Matrix element at ROW: [" << i << "] COLUMN: [" << j << "]";
            cin >> sparseMatrix2[i][j];
        }
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
            if (sparseMatrix2[i][j] != 0)
                size2++;
    int compactMatrix2[size2 + 1][3] = {0};
    compactMatrix2[0][0] = row_size;
    compactMatrix2[0][1] = col_size;
    compactMatrix2[0][2] = size2;
    k = 1;
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if (sparseMatrix2[i][j] != 0)
            {
                compactMatrix2[k][0] = i;
                compactMatrix2[k][1] = j;
                compactMatrix2[k][2] = sparseMatrix2[i][j];
                k++;
                b.insert(i, j, sparseMatrix2[i][j]);
            }
        }
    }

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << sparseMatrix2[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < size2 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << " " << compactMatrix2[i][j];

        cout << "\n";
    }

    cout << "Addition: ";
    a.add(b);
    cout << "\nMultiplication: ";
    a.multiply(b);
    cout << "\nTranspose: ";
    sparse_matrix atranspose = a.transpose();
    atranspose.print();

    return 0;
}
