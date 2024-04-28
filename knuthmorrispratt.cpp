#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

void ComputePrefix(string P, int PI[])
{
	int m,k,q;
	m = P.length()-1;
	
	PI[1] = 0;
	k = 0;
	
	for(q=2;q<=m;q++)
	{
		while(k>0 && P[k+1]!=P[q])
		{
			k = PI[k];
		}
		
		if(P[k+1]==P[q])
		{
			k = k + 1;
		}
		
		PI[q] = k;
	}

}

void KMP(string T, string P)
{
	int m,n,i,q,count;
	
	m = P.length()-1;
	n = T.length()-1;
	
	int *PI = new int[m+1];
	ComputePrefix(P,PI);
	//Display PI
	cout<<"\nPreprocessing Result:";
	for(i=1;i<=m;i++)
		cout<<"\n"<<P[i]<<" - "<<PI[i];
	
	cout<<"\n\n...Searching for Pattern...\n";
	count=0;
	q = 0;
	for(i=1;i<=n;i++)
	{
		while(q>0 && P[q+1]!=T[i])
		{
			q = PI[q];
		}
		if(P[q+1]==T[i])
		{
			q = q + 1;
		}
		if(q==m)
		{
			cout<<"\nFound @ Shift: "<<i-m;
			q = PI[q];
			count++;
		}
	}
	if(count==0)
		cout<<"\n\nPatten Not Found...";
	else
		cout<<"\n\nPattern Found "<<count<<" times...";
	
}


int main()
{
	string T,P;
  	cout<<"\n\nEnter Main String: ";
  	cin>>T;
 	cout<<"\nEnter Pattern To Be Searched: ";
 	cin>>P;
 	/*Test Case - 1
  	T = "abaababacabababacab";
  	P = "ababaca";
`	*/  
 	 //Add 0th character as dummy
	T = " "+T;
	P = " "+P;
  
  	KMP(T,P);
  	
  	
}
