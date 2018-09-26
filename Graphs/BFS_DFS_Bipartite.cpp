/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
  private:
    int V;            // No. of vertices
    vector<int> *adj; // Adjacency list
    bool is_bidirectional = true;

  public:
    Graph(int v, int bidirectional = true)
    {
        V = v;
        adj = new vector<int>[v + 1];
        is_bidirectional = bidirectional;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        if (is_bidirectional)
            adj[v].push_back(u);
    }
    void printAdjList()
    {
        for (int i = 1; i <= V; i++)
        {
            cout << i << " -> ";
            for (auto j : adj[i])
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // DFS
    void DFS(int node = 1)
    {
        bool visited[V + 1];
        for (auto &i : visited)
            i = false;
        stack<int> s;
        s.push(node);
        visited[node] = true;
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            cout << curr << " ";
            for (auto node : adj[curr])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    s.push(node);
                }
            }
        }
    }
    // BFS
    void BFS(int node = 1)
    {
        bool visited[V + 1];
        for (auto &i : visited)
            i = false;
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();
            for (auto node : adj[curr])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
    }
    // Bipartite check
    bool isBipartite()
    {
        vector<int> color(V + 1, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int node = 1; node <= V; node++)
        {
            if (color[node] == -1)
            {
                color[node] = 0;
                q.push(node);
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (auto edge : adj[curr])
                    {
                        if (color[edge] == -1)
                        {
                            q.push(edge);
                            color[edge] = 1 - color[curr];
                        }
                        else
                        {
                            is_bipartite &= (color[curr] != color[edge]);
                        }
                    }
                }
            }
        }
        return is_bipartite;
    }

};
int main()
{

    return 0;
}