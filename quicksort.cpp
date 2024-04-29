#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int count = 0;

int Partition(int a[],int s,int e)
{
	int key = a[e];
	int i = s-1;
	int j;
	for(j=s;j<=e;j++)
	{
		if(a[j]<=key)
		{
			i=i+1;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		count++;
	}
	return i;
}


int RPartition(int a[],int s,int e)
{
	srand(time(NULL));
	int r=(rand()%(e-s+1));
	swap(a[r],a[e]);
	int m=Partition(a,s,e);
	count++;
	return m;
	

}
int RQuickSort(int a[],int s,int e)
{
	count++;
	if(s>=e)
		return;
	int m=RPartition(a,s,e);
	RQuickSort(a,s,m-1);
	RQuickSort(a,m+1,e);
}

int main()
{
	int n,i,j,temp;
	cout<<"Enter the no.of elements: ";
	cin>>n;
	int a[n];
	ofstream fout("RQInput.txt");
	srand ((long int)clock());
	for(i=0;i<n;i++)
		fout<< rand()%n<<"\t";
	fout.close();

	ifstream fin;
	fin.open("RQInput.txt");
	for(i=0;i<n;i++)
	{
		fin >> a[i];
	}
	fin.close();

	cout<<"Random:"<<endl;
	RQuickSort(a,0,n-1);
	cout<<"No.of Iterations: "<<count<<endl;
	cout<<"Ordered:"<<endl;
	RQuickSort(a,0,n-1);
	cout<<"No.of Iterations: "<<count<<endl;
   for(i=0,j=n-1;i<n/2;i++,j--)  
    {     
        temp = a[i];  
        a[i] = a[j];  
        a[j] = temp;  
    } 
	cout<<"Reverse:"<<endl;
	RQuickSort(a,0,n-1); 
	cout<<"No.of Iterations: "<<count<<endl;
}