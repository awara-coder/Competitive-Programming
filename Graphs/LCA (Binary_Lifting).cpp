/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
    using namespace std;

class Graph {
    int V;
    vector < int > *adj;
    int *level;
    int *parent;
    vector < vector < int > > up;
    public:
        Graph(int v) {
            this -> V = v;
            adj = new vector < int > [v + 1]; // Using 1-based indexing
            level = new int[v + 1];
            parent = new int[v + 1];
            up.resize(v + 1);
            for (int i = 0; i <= v; i++) {
                up[i].resize(ceil(log2(v + 1)) + 1, -1);
            }
            for (int i = 0; i <= v; i++) {
                level[i] = -1;
                parent[i] = -1;
            }
            level[0] = 0;
        }
    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int root = 1, int lvl = 1, int p = 0) {
        parent[root] = p;
        level[root] = 1 + level[p];
        up[root][0] = p;
        for (auto child: adj[root]) {
            if (child != p) {
                DFS(child, lvl + 1, root);
            }
        }
    }
    void PreCompute() {
        DFS(); // Preparing the level and parent array
        up[1][0] = -1;
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= ceil(log2(V + 1)); j++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }
    int FindParent(int node, int lvl) {
        if (lvl > ceil(log2(V + 1)) || node < 0) {
            return -1;
        }
        if (lvl == 0) {
            return node;
        }
        if (lvl % 2 != 0) {
            return FindParent(up[node][0], lvl - 1);
        } else {
            return FindParent(up[node][lvl / 2], lvl / 2);
        }
    }

    int LCA(int u, int v) {
        if (u == v)
            return v;
        if (level[u] != level[v]) {
            if (level[u] > level[v])
                swap(u, v);
            int difference = level[v] - level[u];
            v = FindParent(v, difference);
            if (u == v) {
                return v;
            }
        }
        for (int i = ceil(log2(V + 1)); i > 0; i--) {
            int pu = FindParent(u, i);
            int pv = FindParent(v, i);
            if (pu != -1)
                if (pu != pv) {
                    return LCA(pu, pv);
                }
        }
        return up[u][0];
    }
    void PrintUp(void) {
        for (int i = 1; i <= V; i++) {
            cout << i << " : ";
            for (int j = 0; j <= ceil(log2(V + 1)); j++) {
                cout << up[i][j] << " ";
            }
            cout << endl;
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

    void PrintLevel(void) {
        for (int i = 1; i <= V; i++)
            cout << i << " : " << level[i] << endl;
        cout << endl;
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
    g.PreCompute();
    g.PrintLevel();
    g.PrintUp();

    cout << "\n=============================================\nQuest for LCA start here \n\n";
    cout << g.LCA(2, 3);
    return 0;
}
