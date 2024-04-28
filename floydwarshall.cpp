#include<iostream>
#include<iomanip>

#define MAX 20
#define INF 99999
#define NIL -1

using namespace std;

// Function to perform Floyd Warshall algorithm
void FloydWharshal(int Cost[][MAX],int Dist[][MAX],int Parent[][MAX],int n)
{
    int i,j,k;
    int D[MAX][MAX][MAX];
    int P[MAX][MAX][MAX];
    
    // Initialize distance and parent matrices
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            D[0][i][j] = Cost[i][j]; // Initialize distance matrix with edge weights
            if(D[0][i][j]==0 || D[0][i][j]==INF)
                P[0][i][j] = NIL; // Initialize parent matrix with NIL for non-existent edges
            else
                P[0][i][j] = i; // Set parent as source vertex i for existing edges
        }
    }
    
    // Loop through all intermediate vertices
    for(k=1;k<=n;k++)
    {
        // Update distance and parent matrices
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                // If a shorter path is found through vertex k, update matrices
                if(D[k-1][i][k]+D[k-1][k][j] < D[k-1][i][j] )
                {
                    D[k][i][j] = D[k-1][i][k]+D[k-1][k][j]; // Update distance matrix
                    P[k][i][j] = P[k-1][k][j]; // Update parent matrix
                }
                else
                {
                    D[k][i][j] = D[k-1][i][j]; // Keep previous distance
                    P[k][i][j] = P[k-1][i][j]; // Keep previous parent
                }
            }
        }
    }
    
    // Copy final distance and parent matrices
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            Dist[i][j] = D[n][i][j]; // Final distance matrix
            Parent[i][j] = P[n][i][j]; // Final parent matrix
        }
    }
}

int main()
{
    int n;
    int i,j;
    
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    int Cost[MAX][MAX];
    
    // Input cost matrix
    cout << "Enter the cost matrix (INF for infinity):\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> Cost[i][j];
        }
    }
    
    int Dist[MAX][MAX];
    int Parent[MAX][MAX];
    
    // Perform Floyd-Warshall algorithm
    FloydWharshal(Cost,Dist,Parent,n);
    
    // Output distance matrix
    cout<<"\n\nDistance Matrix: ";
    for(i=1;i<=n;i++)
    {
        cout<<"\n";
        for(j=1;j<=n;j++)
        {
            if(Dist[i][j]==INF)
                cout<<"INF\t\t";
            else
                cout<<Dist[i][j]<<"\t\t";
        }       
    }
    
    // Output parent matrix
    cout<<"\n\nParent Matrix: ";
    for(i=1;i<=n;i++)
    {
        cout<<"\n";
        for(j=1;j<=n;j++)
        {
            if(Parent[i][j]==NIL)
                cout<<"NIL\t\t";
            else
                cout<<Parent[i][j]<<"\t\t";
        }       
    }
    
    return 0;
}
