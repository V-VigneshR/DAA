// Matrix Chain Multiplication - Optimal Ordering
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include<limits.h>
using namespace std;

long int cnt = 0;

// Matrix chain Ordering - Divide and Conquer Approach
int MatrixChainDC(int p[], int i, int j) {
    // Base case: If there is only one matrix in the sequence
    if (i == j)
        return 0;

    int k;
    int min = INT_MAX;
    int t;
    // Find the minimum number of scalar multiplications needed to compute
    // the matrix chain product from matrix i to j
    for (k = i; k < j; k++) {
        cnt++;
        // Compute the number of scalar multiplications needed to compute
        // subproblems and combine them
        t = MatrixChainDC(p, i, k) + MatrixChainDC(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        // Update the minimum if the current value is smaller
        if (t < min)
            min = t;
    }
    return min;
}

// Matrix Chain Ordering - Dynamic Programming Approach
long int MatrixChainDP(int p[], int n, long int m[][100], int s[][100]) {
    int i, j, len, k;
    long int q;
    // Initialize the base case where there is only one matrix in the sequence
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // Fill in the table bottom-up for increasing subchain lengths
    for (len = 2; len <= n; len++) {
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            m[i][j] = INT_MAX; // Initialize to infinity
            // Iterate over possible split points and compute the minimum
            // number of scalar multiplications
            for (k = i; k <= j - 1; k++) {
                cnt++;
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // Update the minimum if the current value is smaller
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Record the split point
                }
            }
        }
    }
    return m[1][n]; // Return the minimum number of scalar multiplications
}

// Function to print the optimal parenthesization
void PrintOptimal(int s[][100], int i, int j) {
    if (i == j)
        cout << "A" << i; // Base case: Print single matrix
    else {
        cout << "(";
        // Recursively print optimal parenthesization for left and right subchains
        PrintOptimal(s, i, s[i][j]);
        PrintOptimal(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n = 5; // Number of matrices
    int p[] = {6, 5, 2, 6, 2, 4}; // Matrix dimensions

    cout << "\nMatrix Chain Multiplication - Optimal Ordering";
    cout << "\n\nInput:";
    cout << "\n\tNumber of Matrices: " << n;
    cout << "\n\tMatrices Dimensions: ";
    for (int i = 0; i <= n; i++)
        cout << "\t" << p[i];

    // Divide & Conquer Approach
    cout << "\n\nDivide & Conquer Approach:";
    long int minDC;
    cnt = 0;
    minDC = MatrixChainDC(p, 1, n);
    cout << "\n\nMinumum Number of Multiplications Required: " << minDC;
    cout << "\nNumber of Active Operations: " << cnt;

    // Dynamic Programming Approach
    cout << "\n\nDynamic Programming Approach:";
    long int minDP;
    long int m[100][100]; // Table to store minimum number of multiplications
    int s[100][100]; // Table to store split points for optimal parenthesization

    // Initialize tables
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            m[i][j] = -1; // Initialize to -1
            s[i][j] = -1; // Initialize to -1
        }
    }

    cnt = 0;
    minDP = MatrixChainDP(p, n, m, s);
    cout << "\n\nMinumum Number of Multiplications Required: " << minDP;
    cout << "\nNumber of Active Operations: " << cnt;

    cout << "\n\nOptimal Solution: ";
    // Print optimal parenthesization
    PrintOptimal(s, 1, n);

    return 0;
}