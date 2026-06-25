#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    set<int> st;
    long long ans = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        if (st.find(v[r]) != st.end())
        {
            while (l <= r && st.find(v[r]) != st.end())
            {
                st.erase(v[l++]);
            }
        }
        st.insert(v[r]);
        ans+=(r-l+1);
        r++;
        // cout<<l<<" "<<r<<endl;
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
