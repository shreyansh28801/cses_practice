#include <bits/stdc++.h>
using namespace std;

long long query(int node, int s, int e, int l, int r,
                vector<long long> &segTree)
{
    if (e < l || r < s)
        return LLONG_MAX;

    if (s >= l && e <= r)
        return segTree[node];

    int mid = (s + e) / 2;

    long long al = query(2 * node, s, mid, l, r, segTree);
    long long ar = query(2 * node + 1, mid + 1, e, l, r, segTree);

    return min(al, ar);
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    //pre processing
    while (__builtin_popcount(n) != 1)
    {
        n++;
        a.push_back(INT_MAX);
    }

    vector<long long> segTree(2 * n);

    for (int i = n; i < 2 * n; i++)
        segTree[i] = a[i - n];

    for (int i = n - 1; i > 0; i--)
        segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        cout << query(1, 0, n - 1, l, r, segTree) << '\n';
    }

    return 0;
}