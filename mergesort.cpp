#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;

void merge(int a[],int p,int q,int r,int &c)
{
int n1=q-p+1;
int n2=r-q;

int l[n1];
int r1[n2];

int j,k;
j=0;k=0;

for(int i=p;i<=r;i++)
{
if(i<=q)
{
l[j]=a[i];
j++;
}
else
{
r1[k]=a[i];
k++;
}
c++;
}

l[n1]=999;
r1[n2]=999;

j=0;k=0;

for(int i=p;i<=r;i++)
{
if(l[j]<r1[k])
{
a[i]=l[j];
j++;
}
else
{
a[i]=r1[k];
k++;
}
c++;
}
}
void mergesort(int a[],int p,int r,int &c)
{
if(p>=r)
return ;
int q=(p+r)/2;
mergesort(a,p,q,c);
mergesort(a,q+1,r,c);
merge(a,p,q,r,c);
}

void disp(int a[],int n)
{
for(int i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}
}


int main()
{


char s;
do
{

int *a;
int n,c;
cout<<"enter number of entries:"<<endl;
cin>>n;
a=new int[n];
ofstream of;
ifstream in;

of.open("ip.txt");

for(int u=0;u<n;u++)
{
srand ((long int)clock());
of<<"\t"<<rand()%n;
}
of.close();

in.open("ip.txt");
for(int m=0;m<n;m++)
{
in>>a[m];
}
in.close();

mergesort(a,0,n-1,c);
cout<<"no of comparisons(unsorted):-"<<"\t"<<c<<endl;
disp(a,n);

mergesort(a,0,n-1,c);
cout<<"no of comparisons(sorted):-"<<"\t"<<c<<endl;


for(int b=0;b<n/2;b++)
{
        int temp = a[b];
        a[b] = a[n-b-1];
        a[n-b-1] = temp;
}

mergesort(a,0,n-1,c);
cout<<"no of comparisons(reverse):-"<<"\t"<<c<<endl;

cout<<"press 'o'to stop"<<endl;
cin>>s;
}while(s!='o');


}