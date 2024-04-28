//Bucket Sort
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<cmath>

//For linked list ADT operations
//#include "MyDataStructures.h"
struct Node
{
	double data;
	Node *next;	
};

class SList
{
	private:
		Node *a;
		int size;
	
	public:
		SList();
		bool insertFront(double);
		bool ElementAt(int,double&);
		void Sort();
		int GetSize()	{	return size;		} 
		
};
SList::SList()
{
	a = NULL;
	size = 0;
}
void SList::Sort()
{
	Node *i,*j;
	double t;
	
	i = a;
	for(i=a;i!=NULL;i=i->next)
	{
		for(j = i->next;j!=NULL;j=j->next)
		{
			if(j->data<i->data)
			{
				t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
	
}
bool SList::insertFront(double x)
{
	//New Node Creation
	Node *n;
 	n = new Node;
	
	if(n==NULL)
	{
		return false;
	}
	
	//Initialization
	n->data = x;
	n->next = NULL;
		
	//Link the New Node in the proper position	
	n->next = a;
	a = n;
	
	//Increase the size of the list
	size++;
	
	return true;

}


bool SList::ElementAt(int p, double &x)
{
	
	Node *t = a;
	int c=1;
	while(t!=NULL)
	{
		if(c==p)
		{
			x = t->data;
			return true;
		}
		
		t = t->next;
		c++;
	}
	
	return false;
}


using namespace std;

long int count=0;

void BucketSort(double a[],int n)
{
	SList *Buckets;
	Buckets = new SList[n];
	
	int bNo;
	for(int i=0;i<n;i++)
	{
		bNo = a[i]*n;
		Buckets[bNo].insertFront(a[i]);
		count++;
	}
	
	for(int i=0;i<n;i++)
	{
		count++;
		Buckets[i].Sort();
	}
	
	//Concatenating buckets
	double t;
	for(int i=0,j=0;i<n;i++)
	{
		//cout<<"\nBucket Number: "<<i;
		//Buckets[i].display();
			for(int p=1;p<=Buckets[i].GetSize();p++)
			{
				count++;
				if(Buckets[i].ElementAt(p,t))
				{
					a[j++] = t;
				}
			}

	}
}
int main()
{
	
	cout<<showpoint<<setprecision(4);
	
	ofstream outf;
	ifstream inf;

	clock_t st,end;
	double etime;

	int n;
	double *a;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	a = new double [n];
	
	//Counting the maximum number of digits. Max value is n-1
	int tmp=n-1,d=0;
	while(tmp!=0)
	{
		d++;
		tmp/=10;
	}
	
	srand((long int)clock());
	
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<(double)((rand()%n)/pow(10,d));
	}
	outf.close();
	
	//Bucket Sort
	
	//Reading input in array from input file
		
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	
	st = clock();
	
	count = 0;
	BucketSort(a,n);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;

	//Writing sorted numbers to output file
	outf.open("BucketOut.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	
	cout<<"\nBucket Sort:";
	cout<<"\nTotal Active Operations: "<<count;
	cout<<"\nExecution Time: "<<etime<<" Seconds\n";
	

	delete(a);
	
}
