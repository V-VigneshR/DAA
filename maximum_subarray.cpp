#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Function to solve the maximum subarray problem using brute force strategy
void maxSubarray_BF(int A[], int n, int& count) {
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            count++; // Increment count for each comparison
            sum += A[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
}

// Function to solve the maximum subarray problem using divide and conquer strategy
void maxSubarray_DC(int A[], int low, int high, int& max_sum, int& count) {
    if (low == high) {
        max_sum = A[low];
        return;
    }

    int mid = (low + high) / 2;

    int left_max, right_max, cross_max;
    maxSubarray_DC(A, low, mid, left_max, count);
    maxSubarray_DC(A, mid + 1, high, right_max, count);

    int left_sum = INT_MIN;
    int right_sum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        count++; // Increment count for each comparison
        sum += A[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        count++; // Increment count for each comparison
        sum += A[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    cross_max = left_sum + right_sum;

    max_sum = max(max(left_max, right_max), cross_max);
}

int main() {
    // Generate input data containing positive and negative numbers
    ofstream fout("input_maxSubarray.txt");
    srand(time(0));
    for (int i = 0; i < 10000; i++) {
        int num = rand() % 30;
        if (rand() % 2 == 0)
            fout << -1 * num << "\t";
        else
            fout << num << "\t";
    }
    fout.close();

    // Read input data from file
    ifstream fin("input_maxSubarray.txt");
    const int N = 10000;
    int A[N];
    for (int i = 0; i < N; i++)
        fin >> A[i];
    fin.close();

    int count_bf = 0, count_dc = 0;
    int max_sum_bf, max_sum_dc;

    // Brute force approach
    maxSubarray_BF(A, N, count_bf);
    cout << "Basic operations (Brute Force): " << count_bf << endl;

    // Divide and conquer approach
    maxSubarray_DC(A, 0, N - 1, max_sum_dc, count_dc);
    cout << "Basic operations (Divide and Conquer): " << count_dc << endl;

    return 0;
}
