#include <iostream>
#define MAXN 10 // Maximum n
#define MAXM 1024 // Maximum numbers of Solutions - (Condition: 2 power n <= 1024)

using namespace std;

struct Subset {     
    int X[MAXN];
    int n;
    Subset(int size) {
        n = size;
        for (int i = 0; i < n; i++)
            X[i] = 0;
    }
    Subset() {}
};

void PrintSubset(Subset ssAll[], int solutionSize, int set[], int n) {
    cout << "\n\tNumber of Solutions: " << solutionSize;

    cout << "\n\tSolutions: ";
    for (int i = 0; i < solutionSize; i++) {
        cout << "\n\t\t{ ";
        for (int j = 0; j < n; j++) {
            if (ssAll[i].X[j])
                cout << set[j] << "\t";
        }
        cout << " }";
    }
}

void SubSetSum(int i, int n, int set[], int balanceSum, Subset ss, Subset ssAll[], int &solutionSize) {
    if (balanceSum < 0) {
        // No Solution found... Backtrack..
        return;
    }
    if (balanceSum == 0) {
        // Solution Found...
        // Record the Solution...
        ssAll[solutionSize++] = ss;

        // Backtrack...
        return;
    }

    // If No more choices... Backtrack...
    if (i == n)
        return;

    // If i is included
    ss.X[i] = 1;
    SubSetSum(i + 1, n, set, balanceSum - set[i], ss, ssAll, solutionSize);

    // If i is not included
    ss.X[i] = 0;
    SubSetSum(i + 1, n, set, balanceSum, ss, ssAll, solutionSize);
}

// Driver code
int main() {
    int sum;
    int n;
    Subset ss;
    Subset ssAll[MAXM];
    int solutionSize;

    // Test case 1
    int set1[] = {10, 7, 5, 18, 12, 20, 15};
    sum = 35;
    n = 7;
    ss = Subset(n);
    for (int i = 0; i < MAXM; i++)
        ssAll[i] = Subset(n);

    solutionSize = 0;
    SubSetSum(0, n, set1, sum, ss, ssAll, solutionSize);

    cout << "\n\nTest Case 1: ";
    PrintSubset(ssAll, solutionSize, set1, n);

    // Test case 2
    int set2[] = {3, 34, 4, 12, 5, 2};
    sum = 30;
    n = 6;
    ss = Subset(n);
    for (int i = 0; i < MAXM; i++)
        ssAll[i] = Subset(n);

    solutionSize = 0;
    SubSetSum(0, n, set2, sum, ss, ssAll, solutionSize);

    cout << "\n\nTest Case 2: ";
    PrintSubset(ssAll, solutionSize, set2, n);

    // Test case 3
    int set3[] = {3, 5, 2, 10, 8, 6};
    sum = 10;
    n = 6;
    ss = Subset(n);
    for (int i = 0; i < MAXM; i++)
        ssAll[i] = Subset(n);

    solutionSize = 0;
    SubSetSum(0, n, set3, sum, ss, ssAll, solutionSize);

    cout << "\n\nTest Case 3: ";
    PrintSubset(ssAll, solutionSize, set3, n);

    return 0;
}
