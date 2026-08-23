#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Stack
{
    vector<ll> val;
    vector<ll> pref;

    inline void push(ll x)
    {
        val.push_back(x);

        if (pref.empty())
            pref.push_back(x);
        else
            pref.push_back(pref.back() | x);
    }

    inline void pop()
    {
        val.pop_back();
        pref.pop_back();
    }

    inline ll top()
    {
        return val.back();
    }

    inline ll getOR()
    {
        return pref.empty() ? 0 : pref.back();
    }

    inline bool empty()
    {
        return val.empty();
    }
};

inline void pushQueue(Stack &in, ll x)
{
    in.push(x);
}

inline void popQueue(Stack &in, Stack &out)
{
    if (out.empty())
    {
        while (!in.empty())
        {
            ll x = in.top();
            in.pop();

            out.push(x);
        }
    }

    out.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    Stack in, out;

    ll cur = x;

    // First window
    for (int i = 0; i < k; ++i)
    {
        pushQueue(in, cur);

        cur = (a * cur + b) % c;
    }

    ll ans = in.getOR() | out.getOR();

    // Remaining windows
    for (int i = k; i < n; ++i)
    {
        // Remove oldest element
        popQueue(in, out);

        // Add newest element
        pushQueue(in, cur);

        // OR of current window
        ans ^= (in.getOR() | out.getOR());

        // Generate next element
        cur = (a * cur + b) % c;
    }

    cout << ans << '\n';

    return 0;
}