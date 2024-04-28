Find what you need faster … Home is your new landing page and surfaces your most relevant files and folders
//Counting Sort
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

long int count=0;

void CountingSort(int *a, int *b, int n, int k)
{
	int *c;
	
	c = new int[k+1];
	
	for(int i=0;i<=k;i++)
	{
		count++;
		c[i] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		count++;
		c[a[i]] += 1; 
	}
	for(int i=1;i<=k;i++)
	{
		count++;
		c[i] += c[i-1];
	}
	
	for(int i=n;i>=1;i--)
	{
		count++;
		b[c[a[i]]] = a[i];
		c[a[i]] -= 1;
	}
		
	delete(c);
}

int main()
{
	cout<<showpoint<<setprecision(12);
	
	ofstream outf;
	ifstream inf;

	clock_t st,end;
	double etime;

	int n;
	int *a,*b;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	a = new int [n+1];
	b = new int [n+1];


	srand((long int)clock());
	
	int k;
	
	//Maximum element value is restricted between 1 and n
	k = n;
	
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%(k+1);
	}
	outf.close();
	
	//Counting Sort
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=1;i<=n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	st = clock();
	
	count = 0;
	CountingSort(a,b,n,k);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;

	//Writing sorted numbers to output file
	outf.open("CountOut.txt");
	for(int i=1;i<=n;i++)
	{
		outf<<"\t"<<b[i];
	}
	outf.close();
	
	cout<<"\nCounting Sort:";
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<etime<<" Seconds\n";
	

	delete(a);
	delete(b);
}