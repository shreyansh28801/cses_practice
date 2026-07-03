#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    map<int, int> mp;
    long long ans = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        mp[v[r]]++;
        while (l <= r && (int)mp.size() > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
                mp.erase(v[l]);
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
