#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> s;

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        s.push_back(x);
    }
    map<int, int> freq;
    int l = 0, r = 0;

    int ans = 0;

    while (r < n)
    {
        if (freq.find(s[r]) != freq.end())
        {
            while (l <= r && freq[s[r]] > 0)
            {
                freq[s[l]]--;
                if (freq[s[l]] == 0)
                    freq.erase(s[l]);
                l++;
            }
            ans = max(ans, (r - l + 1));
        }
        freq[s[r]]++;
        ans = max(ans, (r - l + 1));
        r++;
    }

    cout << ans;
}

int main()
{
    solve();
}

// 2 4 1 5 3