/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int **adj;
    int v;
    bool is_bidirectional = true;

  public:
    Graph(int v, bool is_bidirectional = true)
    {
        this->v = v;
        adj = new int *[v + 1];
        for (int i = 0; i <= v; i++)
        {
            adj[i] = new int[v + 1];
        }
        for (int i = 0; i <= v; i++)
            for (int j = 0; j <= v; j++)
                adj[i][j] = INT_MAX; // Assigning distance bw all pairs to inf
        for (int i = 0; i <= v; i++)
            adj[i][i] = 0; // Assigning distance bw same node to 0
        this->is_bidirectional = is_bidirectional;
    }
    void addEdge(int u, int v, int dist)
    {
        adj[u][v] = dist;
        if (is_bidirectional)
            adj[v][u] = dist;
    }
    void FloydWarshall(void) // O(N*N*N) Complexity
    {
        for (int k = 1; k <= v; k++)
        {
            for (int i = 1; i <= v; i++)
            {
                for (int j = 1; j <= v; j++)
                {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
                    {
                        adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
                    }
                }
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (adj[i][j] != INT_MAX)
                {
                    cout << setw(5) << adj[i][j] << " ";
                }
                else
                {
                    cout << setw(5) << "N/A"
                         << " ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(4);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 3, 1);
    g.FloydWarshall();
    g.print();
    return 0;
}