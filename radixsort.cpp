#include<iostream>
using namespace std;
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
void CountSort(int A[], int n, int exp)
{
int count[10] = {0};
int *output=new int[n];
for(int j = 0; j < n; j++)
count[(A[j]/exp)%10]++;
for(int i = 1; i < 10; i++)
count[i] += count[i-1];
for(int j = n-1; j >= 0; j--)
{
output[count[(A[j]/exp)%10]-1] = A[j];
count[(A[j]/exp)%10]--;
}
for(int i = 0; i < n; i++)
A[i] = output[i];
}
void RadixSort(int A[], int n)
{
int m = getMax(A,n);
for(int exp = 1; m / exp > 0; exp *= 10)
CountSort(A, n, exp);
}
int main()
{
int A[] = {543, 986, 717, 690, 450};
int n = sizeof(A)/sizeof(A[0]);
RadixSort(A, n);
cout<<"Sorted Array:";
for(int i = 0 ; i < n; i++)
cout<<A[i]<<"\t";
}
