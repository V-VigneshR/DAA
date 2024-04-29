#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

// Function to compute the prefix function for the pattern P
void ComputePrefix(string P, int PI[])
{
    int m, k, q;
    m = P.length() - 1; // Length of the pattern

    PI[1] = 0; // Initializing the first value of PI to 0
    k = 0; // Initializing k to 0

    // Loop to compute prefix function PI[q] for each q from 2 to m
    for(q = 2; q <= m; q++)
    {
        // While loop to backtrack k if characters at indices k+1 and q in P do not match
        while(k > 0 && P[k + 1] != P[q])
        {
            k = PI[k]; // Backtrack k using the previously computed values in PI
        }

        // If characters at indices k+1 and q in P match, increment k
        if(P[k + 1] == P[q])
        {
            k = k + 1;
        }

        // Store the value of k in PI[q]
        PI[q] = k;
    }
}

// Function to perform Knuth-Morris-Pratt string matching algorithm
void KMP(string T, string P)
{
    int m, n, i, q, count;

    m = P.length() - 1; // Length of pattern P
    n = T.length() - 1; // Length of main string T

    int *PI = new int[m + 1]; // Array to store prefix function values

    ComputePrefix(P, PI); // Compute prefix function for pattern P

    // Display the prefix function values
    cout << "\nPreprocessing Result:";
    for(i = 1; i <= m; i++)
    {
        cout << "\n" << P[i] << " - " << PI[i];
    }

    cout << "\n\n...Searching for Pattern...\n";
    count = 0; // Variable to count occurrences of pattern P in main string T
    q = 0; // Initialize q to 0

    // Loop through the characters of main string T
    for(i = 1; i <= n; i++)
    {
        // While loop to backtrack q if characters at indices q+1 and i in P and T respectively do not match
        while(q > 0 && P[q + 1] != T[i])
        {
            q = PI[q]; // Backtrack q using the previously computed values in PI
        }

        // If characters at indices q+1 and i in P and T respectively match, increment q
        if(P[q + 1] == T[i])
        {
            q = q + 1;
        }

        // If q reaches the length of pattern P, pattern P is found in main string T
        if(q == m)
        {
            cout << "\nFound @ Shift: " << i - m; // Print the shift where pattern P is found
            q = PI[q]; // Backtrack q
            count++; // Increment count of pattern occurrences
        }
    }

    // Output whether pattern P is found or not, and the count of occurrences
    if(count == 0)
    {
        cout << "\n\nPattern Not Found...";
    }
    else
    {
        cout << "\n\nPattern Found " << count << " times...";
    }
}

int main()
{
    string T, P;

    // Input main string T and pattern P from user
    cout << "\n\nEnter Main String: ";
    cin >> T;
    cout << "\nEnter Pattern To Be Searched: ";
    cin >> P;

    // Add dummy characters at index 0 to main string T and pattern P
    T = " " + T;
    P = " " + P;

    // Call the KMP function to search for pattern P in main string T
    KMP(T, P);
}
