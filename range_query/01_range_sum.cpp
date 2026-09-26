#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix(vector<long long> &a)
{
    int n = a.size();
    vector<long long> prefix(n);
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    return prefix;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> p = prefix(a);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        long long sum = p[b];

        if (a > 0)
            sum -= p[a - 1];

        cout << sum << '\n';
    }

    return 0;
}