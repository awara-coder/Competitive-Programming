#include <bits/stdc++.h>

using namespace std;
int *cost;
vector<int> *adj;
bool *visited;

int dfs(int root)
{
    visited[root] = true;
    int c = cost[root];
    for(int i = 0;i<adj[root].size();i++)
    {
        int node = adj[root][i];
        if(!visited[node])
        {
            c = min(c,  dfs(node));
        }
    }
    return c;
}
int main()
{
    int n,m;
    cin >> n >> m;
    adj = new vector<int>[n+1];
    cost  = new int[n+1];
    for(int i = 1;i<=n;i++)
    {
        cin >> cost[i];
    }
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited = new bool[n+1];
    for(int i= 0;i<=n;i++)
        visited[i] =false;
    long long sum  = 0;
    for(int i= 1;i<=n;i++)
    {
        if(!visited[i])
        {
            sum += dfs(i);
        }
    }
    cout << sum << endl;
    return 0;
}
