#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int M = 1e9 + 7;

int AM(int x, int y, int mod) { return ((x % mod) + (y % mod)) % mod; }
int SM(int x, int y, int mod) { return ((x % mod) - (y % mod) + mod) % mod; }
int MM(int x, int y, int mod) { return (1LL * (x % mod) * (y % mod)) % mod; }

void solve()
{
    long long n;
    cin >> n;
    vector<long long> v;
    map<long long, long long> freq;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
        freq[x]++;
    }
    long long ans = 1;

    for (auto it : freq)
    {
        ans *= (it.second + 1);
        ans %= M;
    }

    cout << ans - 1;
}

int main()
{
    solve();
}
