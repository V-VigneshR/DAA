#include<iostream>
#include<time.h>

using namespace std;
#define MAX 20

struct Activity
{
int ano,s,f;
};

void PrintActivities(Activity A[],int n)
{
    cout<<"\n \t\tA.no."<<"\t\t"<<"Start Time"<<"\t\t"<<"Finish Time";

    for(int i=0;i<n;i++)
    {
        cout<<"\n\t\t"<<A[i].ano<<"\t\t"<<A[i].s<<"\t\t"<<A[i].f;
    }
}

void SortActivties(Activity A[],int n)
{
    Activity t;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[j].f<A[i].f)
            {
                swap(A[i],A[j]);
            }
        }
    }

}

int GreedyActivitySelector(Activity A[],Activity S[],int n)
{
    int k, j;
    j = 1; // Initialize the index for the selected activities array (S)
    S[j] = A[0]; // Select the first activity and add it to the selected activities array (S)
    k = 0; // Set k to 1, representing the index of the last selected activity

    // Iterate through the remaining activities starting from the second one
    for (int m =1; m < n; m++)
    {
        // Check if the start time of the current activity is greater than or equal to the finish time of the last selected activity
        if (A[m].s >= A[k].f)
        {
            // If the condition is satisfied, select the current activity and add it to the selected activities array (S)
            S[j++] = A[m];
            // Update k to the index of the last selected activity
            k = m;
        }
    }
    // Return the total number of selected activities
    return j;

}
int main()
{
    Activity A[MAX];
    int n;
    cout<<"Enter number of Activities:";
    cin>>n;
    /*srand(clock());: This line seeds the random number generator using the current clock time.
     It ensures that each time you run the program, you get different random numbers.
     for(int i=1;i<=n;i++): This loop iterates over the activities from 1 to n,
      presumably where n is the number of activities.

    A[i].s = (rand()%(int)(n*0.75))+1;: This line generates a random start time for activity i. 
    It uses the rand() function to generate a random integer and then takes the modulo (%) of it with (int)(n*0.75) to ensure that the start time is within 75% of n. The +1 is added to ensure that the start time is at least 1.
    A[i].f = A[i].s + (rand()%(int)(n*.5))+1;: This line generates a random finish time for activity i. 
    It uses the same approach as above but ensures that the finish time is at least s+1 and within 50% of n from the start time.
    A[i].ano = i;: This line assigns the activity number i to the ano (activity number) attribute of the i-th activity.
*/
   /* srand(clock());
    for(int i=0;i<n;i++)
    {
        A[i].s=(rand()%(int)(n*0.75))+1;
        A[i].f=A[i].s+(rand()%(int)(n*0.5))+1;
        A[i].ano=i;
    }*/
    for(int i=0;i<n;i++)
    {
        A[i].ano=i+1;
        cout<<"Ano."<<A[i].ano<<"Start and End:";
        cin>>A[i].s>>A[i].f;
    }
    cout<<"\n List of Activities:";
    PrintActivities(A,n);
    SortActivties(A,n);
    cout<<"\n List of Activities after sorting:";
    PrintActivities(A,n);

    Activity S[MAX];
    int res;
    res=GreedyActivitySelector(A,S,n);
    cout<<"\nList of Selected Activities(Greedy): ";
    PrintActivities(A,res);



}