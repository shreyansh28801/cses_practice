#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a, b;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (long long i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        b.push_back(x);
    }
    multiset<long long> b_mst;
    for (auto it : b)
    {
        b_mst.insert(it);
    }
    long long ans = 0;

    for (auto it : a)
    {
        auto lb = b_mst.lower_bound(it - k);
        auto up = b_mst.upper_bound(it + k);

        if (lb != b_mst.end())
        {
            if (lb != up)
            {
                ans++;
                b_mst.erase(lb);
            }
        }
    }

    cout << ans;
}

int main()
{
    solve();
}


// a = [1000]
// b = [100, 200, 300, 1500, 100000]
// k=5

// [995, 1005]
