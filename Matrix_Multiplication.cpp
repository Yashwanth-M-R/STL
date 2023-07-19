#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> Matrix_Multiplication(const vector<int> &A, const vector<int> &B, int rowA, int colA, int colB)
{
    vector<vector<int>> c(rowA, vector<int>(colB, 0));

    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            for (int k = 0; k < colA; k++)
            {
                c[i][j] += A[i * colA + k] * B[k * colB + j];
            }
        }
    }

    return c;
}

// Function to display a matrix
void Display(const vector<vector<int>> &matrix)
{
    for (const vector<int> &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rowA, colA, rowB, colB;
    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowA >> colA;
    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowB >> colB;
    if (colA != rowB)
    {
        cout << "Matrix multiplication is not possible." << endl;
        return 1;
    }
    vector<int> A(rowA * colA);
    vector<int> B(rowB * colB);
    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            cout << "Enter the element A"
                 << "[" << i << "]"
                 << "[" << j << "]" << endl; // Takes Input for Matrix A
            cin >> A[(i * colA) + j];
        }
    }
    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            cout << "Enter the element B"
                 << "[" << i << "]"
                 << "[" << j << "]" << endl; // Takes Input for Matrix B
            cin >> B[i * colB + j];
        }
    }
    vector<vector<int>> C = Matrix_Multiplication(A, B, rowA, colA, colB);
    cout << "Matrix A" << endl;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            cout << A[(i * colA) + j] << " ";
        }
        cout << endl;
    }
    cout << "matrix B:" << endl;
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            cout << B[(i * colB) + j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix multiplication Returns: " << endl;
    Display(C);
    return 0;
}
