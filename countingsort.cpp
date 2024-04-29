#include<iostream>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;

// Function to find the maximum element in the array
int getMax(int A[], int n)
{
    int max = A[0];
    for(int i = 1; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

// Function to perform Counting Sort
void CountingSort(int A[], int n)
{
    // Find the maximum element in the array
    int max = getMax(A, n);

    // Create an array to store counts of each element
    int count[max+1];

    // Create an array to store the sorted output
    int output[n+1];

    // Initialize count array to all zeros
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    // Count occurrences of each element in the input array
    for(int j = 0; j < n; j++)
        count[A[j]]++;

    // Modify count array to store the actual position of each element in the output array
    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];

    // Build the sorted output array
    for(int j = n-1; j >= 0; j--)
    {
        output[count[A[j]]-1] = A[j];
        count[A[j]]--;
    }

    // Copy the sorted output array to the original array
    for(int i = 0; i < n; i++)
        A[i] = output[i];
}

int main()
{
    int n;
    int *a,*b;

    // Input the size of the array
    cout<<"\nEnter n:";
    cin>>n;

    // Dynamically allocate memory for the arrays
    a = new int [n+1];
    b = new int [n+1];

    // Input the elements of the array
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    // Perform Counting Sort
    CountingSort(a,n);

    // Output the sorted array
    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }

    // Free memory allocated for the arrays
    delete[] a;
    delete[] b;
}
