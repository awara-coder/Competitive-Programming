/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    int *Parent; // Array containing info about parent of element
    int N;       // No. of elements in the Set
    int *Rank;   // Rank of elements in disjoint sets
  public:
    DisjointSet(int n)
    {
        N = n;
        Parent = new int[N + 1];
        Rank = new int[N + 1];
        for (int i = 0; i <= N; i++)
        {
            Parent[i] = i;
            Rank[i] = 1;
        }
    }
    int Find(int a)
    {
        if (Parent[a] == a)
            return a;
        return Parent[a] = Find(Parent[a]); // Path Compression
    }
    void Union(int a, int b)
    {
        int parent_a = Find(a);
        int parent_b = Find(b);
        if (Rank[parent_a] < Rank[parent_b])
            swap(parent_a, parent_b);
        Parent[parent_b] = parent_a;
        if (Rank[parent_a] == Rank[parent_b]) // Union by Rank
            Rank[parent_a]++;
    }
};

int main()
{
    DisjointSet d(5);
    d.Union(1, 2);
    d.Union(2, 3);
    d.Union(1, 5);
    cout << d.Find(2) << endl
         << d.Find(4);
    return 0;
}