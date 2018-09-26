/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void build_seg(int arr[], int seg[], int start, int end, int root)
{
    if (start == end)
    {
        seg[root] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build_seg(arr, seg, start, mid, root * 2 + 1);
    build_seg(arr, seg, mid + 1, end, root * 2 + 2);
    seg[root] = min(seg[root * 2 + 1], seg[root * 2 + 2]);
}
int getmin(int seg[], int l, int r, int start, int end, int root = 0)
{
    if (start >= l && end <= r)
    {
        return seg[root];
    }
    if (r < start || l > end)
    {
        return INT_MAX;
    }
    int mid = (start + end) / 2;
    return min(getmin(seg, l, r, start, mid, root * 2 + 1), getmin(seg, l, r, mid + 1, end, root * 2 + 2));
}
void update(int seg[], int x, int y, int start, int end, int root = 0)
{
    if (start == end)
    {
        seg[start] = y;
        return;
    }
    int mid = (start + end) / 2;
    if (x <= mid)
    {
        update(seg, x, y, start, mid);
    }
    else
    {
        update(seg, x, y, mid + 1, end);
    }
    seg[root] = min(seg[root * 2 + 1], seg[root * 2 + 2]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int size = pow(2, ceil(log2(n) + 1));
    int seg[size];
    build_seg(arr, seg, 0, n - 1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << getmin(seg, l, r, 0, n - 1) << endl;
    }

    return 0;
}