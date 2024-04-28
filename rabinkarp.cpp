#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void RabinKarp(string T, string P, int d, int r)
{
    int i, s, m, n, q, h, fcount, scount;

    // Convert both T and P to lowercase
    for (char &c : T) c = tolower(c); // Convert each character in T to lowercase
    for (char &c : P) c = tolower(c); // Convert each character in P to lowercase

    // Size is excluding 0th dummy character
    m = P.length() - 1; // Length of pattern P
    n = T.length() - 1; // Length of text T

    // Dynamically allocate memory for the integer array t
    int *t = new int[n - m + 1];

    // Compute initial hash values
    q = t[0] = 0;
    for (i = 1; i <= m; i++)
    {
        q = (P[i] + d * q) % r; // Compute hash value for pattern P
        t[0] = (T[i] + d * t[0]) % r; // Compute hash value for initial substring of text T
    }

    // Compute h = d^(m-1) % r
    h = 1;
    for (i = 1; i <= m - 1; i++)
    {
        h = h * d % r;
    }

    // Initialize counters for found and spurious hits
    fcount = scount = 0;

    // Print headers for output
    cout << "\ns\tt[s]\tq\tFound?";
    cout << "\n****************************************";

    // Main loop to search for pattern in text
    for (s = 0; s <= n - m; s++)
    {
        cout << "\n" << s << "\t" << t[s] << "\t" << q << "\t"; // Print current position and hash values

        // Check if hash values match
        if (t[s] == q)
        {
            // Comparing P[1..m] with T[s+1..s+m]
            if (P.substr(1, m) == T.substr(s + 1, m))
            {
                cout << "Yes @ Shift: " << s; // Print match found
                fcount++; // Increment count of found matches
            }
            else
            {
                cout << "Spurious Hit"; // Print spurious hit
                scount++; // Increment count of spurious hits
            }
        }

        // Update hash value for next position
        if (s < n - m)
        {
            t[s + 1] = ((t[s] - T[s + 1] * h) * d + T[s + 1 + m]) % r;
            if (t[s + 1] < 0)
                t[s + 1] += r;
        }
    }

    // Print final results
    if (fcount == 0)
        cout << "\nPatten Not Found...";
    else
        cout << "\n\nPattern Found " << fcount << " times...";

    cout << "\nNumber of Spurious Hit(s): " << scount;

    // Deallocate memory for array t
    delete[] t;
}

int main()
{
    int r, d;
    string T, P;

    // User input for text and pattern
    cout << "\nPatten Searching for Alphabet: {a,b,c...z}, so that d=26";
    cout << "\nGive input strings containing only lower case alphabets";
    cout << "\n\nEnter Main String: ";
    cin >> T;
    cout << "\nEnter Pattern To Be Searched: ";
    cin >> P;

    // Add 0th character as dummy
    T = " " + T;
    P = " " + P;

    // Initialize d, Number of unique characters
    d = 26;

    // Choose prime number
    r = 7;

    // Call RabinKarp function to search for pattern in text
    RabinKarp(T, P, d, r);

    return 0;
}
