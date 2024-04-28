#include<iostream>
using namespace std;

class FloydWarshall 
{
private:
    int W[100][100]; // Weight matrix
    int D[100][100]; // Distance matrix
    int pi[100][100]; // Predecessor matrix
    int m, n; // Size of the matrices
public:
    // Constructor to initialize the weight matrix
    FloydWarshall()
    {
        n = m = 5; // Assuming size of matrices as 5x5
        // Input for the weight matrix
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << "Enter the array element A" <<i<<j;
                cin >> W[i][j];
            }
            cout << endl;
        }
    }

    // Initialize the distance and predecessor matrices
    void init()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                D[i][j] = W[i][j];
                if((i == j) || (W[i][j] == 9999)) // Assuming 9999 represents infinity
                {
                    pi[i][j] = 0; // Initialize predecessor to 0
                }
                else pi[i][j] = i + 1; // Initialize predecessor to source vertex + 1
            }
        }
    }

    // Floyd Warshall algorithm to find shortest paths
    void floydWarshall()
    {
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if((pi[i][k] != 0) && (pi[k][j] != 0) && (D[i][j] > (D[i][k]+ D[k][j])))
                    {
                        D[i][j] = D[i][k]+ D[k][j];
                        pi[i][j] = pi[k][j];
                    }
                }
            }
        }
    }

    // Display the distance and predecessor matrices
    void disp()
    {
        cout << "D matrix :" << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << D[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "PI matrix :" << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << pi[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{ 
    // Create an instance of FloydWarshall class
    FloydWarshall fWarshall = FloydWarshall();
    // Initialize matrices
    fWarshall.init();
    // Perform Floyd Warshall algorithm
    fWarshall.floydWarshall();
    // Display matrices
    fWarshall.disp();

    return 0;
}