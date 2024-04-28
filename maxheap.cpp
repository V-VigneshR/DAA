#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;

 static int c=0;

void maxheapify(int a[],int n,int i)
{
	int l,r,m;
	
	l=2*i+1;
	r=2*i+2;
	
	m=i;
	if(l<=n-1 && a[l]>a[m])
		m=l;
	if(r<=n-1 && a[r]>a[m])
		m=r;
	if(m!=i)
	{
		int t;
		t=a[m];
		a[m]=a[i];
		a[i]=t;
		maxheapify(a,n,m);
	}
}

void buildmaxheap(int a[],int n)
{
	int i;
	for(i=(n-2)/2;i>=0;i--)
	{
		maxheapify(a,n,i);
		c++;
	}
}

void heapsort(int a[],int n)
{
	buildmaxheap(a,n);
	int t;
	while(n>=2)
	{
		t=a[0];
		a[0]=a[n-1];
		a[n-1]=t;
		n--;c++;
		maxheapify(a,n,0);
	}
}

int main()
{
	int n,i,j;
	int* a;
	cout<<"enter total number of elements"<<endl;
	cin>>n;
	a=new int[n];

	
	ofstream of;
	ifstream in;
	
	of.open("inputs.txt");
	srand((long int)clock());
	
	for(int i=0;i<n;i++)
	{
		of<<rand()%n<<"\t";
	}
	of.close();
	
	in.open("inputs.txt");
	for(int i=0;i<n;i++)
	{
		in>>a[i];
	}
	in.close();
	
	cout<<"random"<<endl;
	heapsort(a,n);
	cout<<"Count: "<<c<<endl;
	
	cout<<"sorted: "<<endl;
	heapsort(a,n);
	cout<<"Count: "<<c<<endl;
	

	cout<<"reverse"<<endl;
	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	heapsort(a,n);
	cout<<"Count: "<<c<<endl;

}