/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h >
using namespace std;

class Graph {
    int V;
    vector < int > * adj;
    vector < int > euler;
    int * distance;
    int * first;
    int * segtree;
    public:
        Graph(int v) {
            this -> V = v;
            adj = new vector < int > [v + 1]; // Using 1-based indexing
            distance = new int[v + 1];
            first = new int[v + 1];
            euler.push_back(-1); // setting up for 1-based indexing

        }
    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int root = 1, int h = 1, int parent = 0) // To prepare distance and first array
    {
        // and to undergo euler tour
        euler.push_back(root);
        distance[root] = h;
        first[root] = euler.size() - 1;
        if (adj[root].size() == 1)
            return;
        for (auto to: adj[root]) {
            if (to != parent) {
                dfs(to, h + 1, root);
                euler.push_back(root);
            }
        }
    }
    void BuildSegTree(void) {
        segtree = new int[euler.size() * 4]; // Allocates space for Segment Tree
        build(1, 1, euler.size() - 1);
    }
    void build(int root, int start, int end) {
        if (start == end) {
            segtree[root] = euler[start];
            return;
        }
        int mid = (start + end) / 2;
        build(root * 2, start, mid);
        build(root * 2 + 1, mid + 1, end);
        if (distance[segtree[root * 2]] > distance[segtree[root * 2 + 1]])
            segtree[root] = segtree[root * 2 + 1];
        else
            segtree[root] = segtree[root * 2];
    }
    int RMQ(int start, int end, int qs, int qe, int node = 1) // To perform Range Min Query on Segment Tree
    {
        if (qe < start || qs > end) // No overlap condition
            return -1;
        if (qs <= start && qe >= end) // Complete overlap condition
        {
            return segtree[node];
        }

        int mid = (start + end) / 2; // Partial overlap condition
        int left = RMQ(start, mid, qs, qe, node * 2);
        int right = RMQ(mid + 1, end, qs, qe, node * 2 + 1);
        if (left == -1)
            return right;
        else if (right == -1)
            return left;
        else if (distance[right] > distance[left])
            return left;
        else
            return right;
    }
    int LCA(int u, int v) {
        int a, b;
        a = first[u];
        b = first[v];
        if (a > b)
            swap(a, b);
        return RMQ(1, euler.size() - 1, a, b);
    }
    void PrintFirst(void) {
        for (int i = 1; i <= V; i++) {
            cout << i << " : " << first[i] << endl;
        }
    }
    void PrintAdj(void) {
        for (int i = 1; i <= V; i++) {
            cout << i;
            for (auto edge: adj[i]) {
                cout << " -> " << edge;
            }
            cout << endl;
        }
    }
    void PrintEuler(void) {
        for (int i = 1; i < euler.size(); i++) {
            cout << euler[i] << " ";
        }
        cout << endl;
    }
    void PrintDistance(void) {
        for (int i = 1; i <= V; i++)
            cout << i << " : " << distance[i] << endl;
        cout << endl;
    }
    void PrintSegTree(void) {
        for (int i = 1; i < euler.size() * 4; i++)
            cout << segtree[i] << " for " << i << endl;
    }
};

int main() {
    Graph g(7);
    g.AddEdge(1, 2);
    g.AddEdge(2, 5);
    g.AddEdge(2, 6);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    g.AddEdge(4, 7);
    g.PrintAdj();
    g.dfs();
    g.PrintDistance();
    g.PrintEuler();
    g.PrintFirst();
    g.BuildSegTree();

    cout << "Quest for LCA start here \n\n";
    cout << g.LCA(7, 3);
    return 0;
}
