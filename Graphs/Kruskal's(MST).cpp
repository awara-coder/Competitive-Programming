/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
    int n;
    int *root;

  public:
    UnionFind(int n)
    {
        this->n = n;
        root = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            root[i] = i;
        }
    }
    int find(int a)
    {
        if (root[a] == a)
            return a;
        return root[a] = find(root[a]);
    }
    int Union(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        root[root_u] = root_v;
    }
};

class Graph
{
    vector<pair<int, pair<int, int>>> edgelist; // Edge List (cost, (u,v))
    int V;
    int E;

  public:
    Graph(int V, int E = 0)
    {
        this->V = V;
        this->E = E;
    }
    void Addedge(int u, int v, int cost)
    {
        edgelist.push_back(make_pair(cost, make_pair(u, v)));
        this->E++;
    }
    int Kruskal(int source = 1)
    {
        UnionFind s(V+1);
        int MST_cost = 0;
        for(int i = 0 ;i < E;i++)
        {
            int u = edgelist[i].second.first;
            int v = edgelist[i].second.second;
            int cost = edgelist[i].first;
            if(s.find(u) != s.find(v)) 
            {
                s.Union(u,v);
                MST_cost += cost;
            }
        }
        return MST_cost;
    }
};
