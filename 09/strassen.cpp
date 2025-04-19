#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

// Matrix addition
Matrix add(const Matrix &A, const Matrix &B, int n) {
    Matrix res(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            res[i][j] = A[i][j] + B[i][j];
    return res;
}

// Recursive matrix multiplication (Divide and Conquer)
Matrix mult(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix res(n, vector<int>(n, 0));

    if(n == 1) {
        res[0][0] = A[0][0] * B[0][0];
        return res;
    }

    // Divide matrices into 4 submatrices each
    int mid = n / 2;
    Matrix A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid));
    Matrix A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    Matrix B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid));
    Matrix B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for(int i = 0; i < mid; ++i) {
        for(int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Multiply and combine
    Matrix C11 = add(mult(A11, B11), mult(A12, B21), mid);
    Matrix C12 = add(mult(A11, B12), mult(A12, B22), mid);
    Matrix C21 = add(mult(A21, B11), mult(A22, B21), mid);
    Matrix C22 = add(mult(A21, B12), mult(A22, B22), mid);

    // Join the 4 result matrices into the final result
    for(int i = 0; i < mid; ++i) {
        for(int j = 0; j < mid; ++j) {
            res[i][j] = C11[i][j];
            res[i][j + mid] = C12[i][j];
            res[i + mid][j] = C21[i][j];
            res[i + mid][j + mid] = C22[i][j];
        }
    }

    return res;
}

int main() {
    Matrix A = {{7, 8}, {2, 9}};
    Matrix B = {{14, 5}, {5, 18}};
    Matrix C = mult(A, B);

    for(const auto &row : C) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
