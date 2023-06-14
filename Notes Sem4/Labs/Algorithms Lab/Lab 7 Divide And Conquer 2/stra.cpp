#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void printMatrix(int**, int);
int** standardMultiplication(int**, int**, int);
int** strassensMultiplication(int**, int**, int);
int** strassensMultRec(int**, int**, int);
int** divide(int**, int, int, int);
int** add(int**, int**, int);
int** sub(int**, int**, int);

/*
 * Main function where the execution starts.
 */
int main() {
    int i = 0, j = 0, n = 0;
    cout << "Enter n: ";
    cin >> n;
    if (n < 1) {
        printf("\nError: Invalid matrix dimension!\n\n");
        return 0;
    }

    // To handle when n is not power of k we do the padding with zero
    int pow = 1;
    while (pow < n) {
        pow = pow * 2;
    }

    cout << "\nMatrix A: \n";
    int** matrixA = new int*[pow];
    for (int i = 0; i < pow; i++) {
        matrixA[i] = new int[pow]();
        for (int j = 0; j < pow; j++)
            if (i < n && j < n)
                cin >> matrixA[i][j];
    }

    cout << "\nMatrix B: \n";
    int** matrixB = new int*[pow];
    for (int i = 0; i < pow; i++) {
        matrixB[i] = new int[pow]();
        for (int j = 0; j < pow; j++)
            if (i < n && j < n)
                cin >> matrixB[i][j];
    }

    int** stdRes = standardMultiplication(matrixA, matrixB, pow);
    printf("\nStandard Multiplication Output:\n");
    printMatrix(stdRes, pow);

    printf("\nStrassen's Multiplication Output:\n");
    int** strassensRes = strassensMultiplication(matrixA, matrixB, pow);
    printMatrix(strassensRes, pow);

    for (int i = 0; i < pow; i++) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] stdRes[i];
        delete[] strassensRes[i];
    }
    delete[] matrixA;
    delete[] matrixB;
    delete[] stdRes;
    delete[] strassensRes;
    return 0;
}

/*
 * Function to Print Matrix
 */
void printMatrix(int** matrix, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        printf("\n");
    }
}

/*
 * Standard Matrix multiplication with O(n^3) time complexity.
 */
int** standardMultiplication(int** matrixA, int** matrixB, int n) {
    int** result = new int*[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[n]();
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
result[i][j] += matrixA[i][k] * matrixB[k][j];
}
}
}
return result;
}


int** add(int** matrixA, int** matrixB, int n) {
    int** result = createZeroMatrix(n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int** sub(int** matrixA, int** matrixB, int n) {
    int** result = createZeroMatrix(n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

    void compose(int** matrixA, int** matrixB, int** matrixC, int** matrixD, int n, int** result) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j];
            result[i][j + n] = matrixB[i][j];
            result[i + n][j] = matrixC[i][j];
            result[i + n][j + n] = matrixD[i][j];
        }
    }
}
