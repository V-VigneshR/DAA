#include<iostream>
#include<iomanip>

#define MAX 20

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SList
{
private:
    Node *a;
    int size;

public:
    SList()
    {
        a = NULL;
        size = 0;
    }

    bool insertEnd(int);
    bool ElementAt(int, int&);
    int GetSize() { return size; }
};

// Function to retrieve element at a given position
bool SList::ElementAt(int p, int &x)
{
    Node *t = a;
    int c = 1;
    while (t != NULL)
    {
        if (c == p)
        {
            x = t->data;
            return true;
        }

        t = t->next;
        c++;
    }

    return false;
}

// Function to insert element at the end of the list
bool SList::insertEnd(int x)
{
    Node *n;
    n = new Node;

    if (n == NULL)
    {
        return false;
    }

    n->data = x;
    n->next = NULL;

    if (a == NULL)
    {
        a = n;
        size++;
        return true;
    }

    Node *t;
    t = a;
    while (t != NULL)
    {
        if (t->next == NULL)
        {
            t->next = n;
            size++;
            return true;
        }
        t = t->next;
    }
    return false;
}

// Structure to represent a vertex in the graph
struct Vertex
{
    SList AdjList;  // Adjacency list to store the indices of adjacent vertices
    int Value;      // For easy understanding, the index will be stored as vertex value
    int Parent;     // Index of the parent vertex in the resultant BFS tree
    int Distance;   // Minimum cost from the current vertex to the starting vertex
};

// Class to represent a graph
class Graph
{
private:
    Vertex *V;  // Array of vertices
    int size;   // Number of vertices in the graph

    void Relax(int, int, int [][MAX]);  // Helper function for relaxation

public:
    Graph(int);                         // Constructor to initialize the graph
    void AddEdge(int,int);              // Method to add an edge between two vertices
    bool BellmanFord(int [][MAX],int);  // Method to perform Bellman-Ford algorithm
    void ShowGraph();                   // Method to display the graph
};

// Function to relax an edge during Bellman-Ford algorithm
void Graph::Relax(int u, int v, int w[][MAX])
{
    if (V[v].Distance > V[u].Distance + w[u][v])
    {
        V[v].Distance = V[u].Distance + w[u][v];
        V[v].Parent = u;
    }
}

// Constructor to initialize the graph with given number of vertices
Graph::Graph(int n)
{
    size = n;
    V = new Vertex[n];
    for (int i = 0; i < n; i++)
    {
        V[i].Value = i;
        V[i].Parent = -1;
        V[i].Distance = 9999;  // Initialize distance to infinity
    }
}

// Method to add an edge between two vertices
void Graph::AddEdge(int from, int to)
{
    V[from].AdjList.insertEnd(to);  // Adding 'to' vertex to the adjacency list of 'from' vertex
}

// Method to perform Bellman-Ford algorithm to find shortest paths
bool Graph::BellmanFord(int w[][MAX], int s)
{
    // Initialize Single Source. By default, Distance is infinity for all vertices.
    V[s].Distance = 0;

    int u, v, p, i;

    for (i = 0; i < size - 1; i++)
    {
        for (u = 0; u < size; u++)
        {
            for (p = 1; p <= V[u].AdjList.GetSize(); p++)
            {
                if (V[u].AdjList.ElementAt(p, v))
                {
                    if (w[u][v] != 0)
                    {
                        Relax(u, v, w);  // Relax the edge if needed
                    }
                }
            }
        }
    }

    // Check for negative weight cycles
    for (u = 0; u < size; u++)
    {
        for (p = 1; p <= V[u].AdjList.GetSize(); p++)
        {
            if (V[u].AdjList.ElementAt(p, v))
            {
                if (V[v].Distance > V[u].Distance + w[u][v])
                {
                    return false;  // Negative weight cycle detected
                }
            }
        }
    }

    return true;  // No negative weight cycle found
}

// Method to display the graph
void Graph::ShowGraph()
{
    cout << "D matrix :" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(6) << V[i].Value << " | ";
        }
        cout << endl;
    }
    cout << "PI matrix :" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(6) << V[i].Parent << " | ";
        }
        cout << endl;
    }
}

// Main function
int main()
{
    int n = 5;  // Number of vertices

    // Cost Matrix for the input graph
    int b[][MAX] = { {0, 6, 0, 0, 7},
                     {0, 0, 5, -4, 8},
                     {0, -2, 0, 0, 0},
                     {2, 0, 7, 0, 0},
                     {0, 0, -3, 9, 0} };

    Graph g(n);  // Create a graph with 'n' vertices

    // Add edges to the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                g.AddEdge(i, j);  // Add an edge between vertices 'i' and 'j'
            }
        }
    }

    int s = 0;  // Starting vertex index
    bool res;

    res = g.BellmanFord(b, s);  // Perform Bellman-Ford algorithm

    // Display the result
    if (res)
    {
        cout << "\n\nSingle Source Shortest Path (Bellman-Ford Algorithm) Result:\n";
        g.ShowGraph();
    }
    else
    {
        cout << "\nNegative Weight Cycle is Present.\nSo, Could Not find Shortest Path....";
    }

    return 0;
}
