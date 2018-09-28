/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

class Edge
{
    int s; // Start vertex of Edge
    int e; // End vertex of Edge
    int c; // Cost of the Edge
  public:
    Edge(int start, int end, int cost)
    {
        this->s = start;
        this->e = end;
        this->c = cost;
    }
    int start()
    {
        return this->s;
    }
    int end()
    {
        return this->e;
    }
    int cost()
    {
        return this->c;
    }
};

class EdgeList // Works on 1 based indexing of nodes (first node is numbered 1)
{
    int E = 0; // No. of edges
    int V;

  public:
    vector<Edge> edgelist; // Too lazy to write iterator, so 'public'
    EdgeList(int vertices)
    {
        this->V = vertices;
    }
    void AddEdge(int start, int end, int cost)
    {
        Edge newEdge(start, end, cost);
        edgelist.push_back(newEdge);
        E++;
    }
    int size()
    {
        return E;
    }
    int Bellman_Ford(int source, int destination) // O(VE) Time Complexity
    {
        vector<int> dist(V + 1, INT_MAX);
        dist[source] = 0;
        for (int counter = 0; counter < V - 1; counter++)
        {
            for (auto it : edgelist)
            {
                if (dist[it.start()] < INT_MAX)
                {
                    dist[it.end()] = min(dist[it.end()], dist[it.start()] + it.cost());
                }
            }
        }
        return dist[destination];
    }
};

int main()
{
    EdgeList E(5);
    E.AddEdge(0, 1, -1);
    E.AddEdge(0, 2, 4);
    E.AddEdge(1, 2, 3);
    E.AddEdge(1, 3, 2);
    E.AddEdge(1, 4, 2);
    E.AddEdge(3, 2, 5);
    E.AddEdge(3, 1, 1);
    E.AddEdge(4, 3, -3);
    cout << E.Bellman_Ford(0, 3);
    return 0;
}
