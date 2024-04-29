#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<time.h>
using namespace std;

void merge(int a[],int p,int q,int r,int &c)
{
        int n1=q-p+1;
        int n2=r-q;
        int *L=new int[n1];
        int *R=new int[n2];
        int j=0,k=0;
        
        for(int i=p;i<=r;i++)
        {
                if(i<=q)
                {
                        L[j]=a[i];
                        j++;
                }
                else{
                        R[k]=a[i];
                        k++;
                }
                c++;
        }
        L[n1]=R[n2]=9999;
        j=k=0;
        for(int i=p;i<=r;i++)
        {
                if(L[j]<R[k])
                {
                        a[i]=L[j];
                        j++;

                }
                else{
                        a[i]=R[k];
                        k++;
                }
                c++;    
        }
        


}
void mergesort(int a[],int p,int r,int &c)
{
        if(p>=r)
                return;
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
        int n,c;
        cout<<"Enter number of entries:";
        cin>>n;
        int *a=new int[n];
        cout<<"\n Enter array elements:";
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
        }
        mergesort(a,0,n,c);
        cout<<"After merging:";
        for(int i=0;i<n;i++)
        {
                cout<<"\t"<<a[i];
        }



}