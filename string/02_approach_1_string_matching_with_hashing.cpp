#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int M = 1e9 + 7;
const int N = 1e7 + 10;
vector<int> PrefixHashValue(N);
vector<int> dp_PowOfBaseOfString(N);

ll p = 31;

ll AM(ll a, ll b, ll M)
{
    return ((a % M) + (b % M)) % M;
}

ll SM(ll a, ll b, ll M)
{
    return ((a % M) - (b % M) + M) % M;
}

void RabinKarpRollingHash(string &s)
{
    dp_PowOfBaseOfString[0] = 1;
    PrefixHashValue[0] = (s[0] - 'a' + 1) * dp_PowOfBaseOfString[0];
    for (int i = 1; i < s.size(); i++)
    {
        dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * 1ll * p) % M;
        PrefixHashValue[i] = AM(PrefixHashValue[i - 1], ((s[i] - 'a' + 1) * 1ll * dp_PowOfBaseOfString[i]), M);
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;

    long long dhv = (b[0] - 'a' + 1); // desired hash value
    ll pow = 1;

    for (int i = 1; i < b.size(); i++)
    {
        pow = (pow * p) % M;
        dhv = AM(dhv, (b[i] - 'a' + 1) * pow, M);
    }

    int lo = 0, hi = b.size() - 1;

    RabinKarpRollingHash(a);
    int count = 0;

    while (hi < a.size())
    {
        long long cur_window_hash = SM(PrefixHashValue[hi], (lo > 0 ? PrefixHashValue[lo - 1] : 0), M);
        long long required_hash = ((dhv * 1ll * dp_PowOfBaseOfString[lo]) % M);
        if (required_hash == cur_window_hash)
            count++;

        //cout << lo << " " << hi << " " << cur_window_hash << " " << required_hash << endl;
        lo++;
        hi++;
    }
    cout << count;
}

int main()
{
    solve();
    return 0;
}