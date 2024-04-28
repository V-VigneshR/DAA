//Longest Common Subsequence
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

long int cnt = 0;

//LCS - Dynamic Programming
int LCS_Length_DP(char x[], char y[], int m, int n, char b[][100], int c[][100]) {
    // m and n are the length of x and y respectively
    
    // Filling 0th Column with 0's
    for (int i = 1; i <= m; i++) //note i starts from 1 as j will anyway set c[0,j] as 0! 
    {
        c[i][0] = 0;
        cnt++;
    }
    
    // Filling 0th Row with 0's
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
        cnt++;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cnt++;
            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'C';
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }
    
    return c[m][n];
}

//Print LCS
void PrintLCS(char b[][100], char x[], int m, int n) {
    if (m == 0 || n == 0) {
        return;
    }
    
    if (b[m][n] == 'C') {
        PrintLCS(b, x, m-1, n-1);
        cout << x[m];
    } else if (b[m][n] == 'U') {
        PrintLCS(b, x, m-1, n);
    } else {
        PrintLCS(b, x, m, n-1);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

//LCS - Divide & Conquer
int LCS_Length_DC(char X[], char Y[], int m, int n) {
    cnt++;
    if (m == 0 || n == 0) {
        return 0;
    }
    
    if (X[m-1] == Y[n-1]) {
        return 1 + LCS_Length_DC(X, Y, m-1, n-1);
    } else {
        return max(LCS_Length_DC(X, Y, m, n-1), LCS_Length_DC(X, Y, m-1, n));
    }
}

int main() {
    int n, m;
    char x[100], y[100];
    
    cout << "\nEnter Length of First String: ";
    cin >> m;
    cout << "\nEnter Length of Second String: ";
    cin >> n;
    
    srand(time(NULL));
    
    // Loading numbers to input file
    ofstream outf;
    
    outf.open("in1.txt");
    for (int i = 1; i <= m; i++) {
        char random_char;
        do {
            random_char = rand() % 26 + 'A';
        } while (random_char < 'A' || random_char > 'Z');
        outf << "\t" << random_char;
    }
    outf.close();
    
    outf.open("in2.txt");
    for (int i = 1; i <= n; i++) {
        char random_char;
        do {
            random_char = rand() % 26 + 'A';
        } while (random_char < 'A' || random_char > 'Z');
        outf << "\t" << random_char;
    }
    outf.close();
    
    // Reading input from the files
    ifstream inf;
    
    inf.open("in1.txt");
    for (int i = 1; i <= m; i++) {
        inf >> x[i];
    }
    inf.close();
    x[m] = '\0';
    x[0] = ' ';
    
    inf.open("in2.txt");
    for (int i = 1; i <= n; i++) {
        inf >> y[i];
    }
    inf.close();
    y[n] = '\0';
    y[0] = ' ';
    
    cout << "\n\nX: " << x;
    cout << "\n\nY: " << y;
    
    char b[100][100]; // U - Up, L - Left & C - Cross
    int c[100][100];
    
    int lcs_length = 0;
    
    // LCS - Divide & Conquer
    cnt = 0;
    lcs_length = LCS_Length_DC(x, y, m, n);
    
    cout << "\n\nLongest Common Subsequence Length (Divide & Conquer): " << lcs_length;
    cout << "\nNumber of Active Operations: " << cnt;
    
    // LCS - Dynamic Programming
    cnt = 0;
    lcs_length = LCS_Length_DP(x, y, m, n, b, c);

    cout << "\n\nLongest Common Subsequence Length (Dynamic Programming): " << lcs_length;
    cout << "\nNumber of Active Operations: " << cnt;
    cout << "\n\nLCS: ";
    PrintLCS(b, x, m, n);

    return 0;
}
