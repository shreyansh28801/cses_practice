#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}

template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}

void fu(int cnt[], int x)
{
    for (int i = 0; i < 31; i++)
    {
        if (x & (1LL << i))
            cnt[i]++;
    }
}

void fu1(int cnt[], int x, int &or_sum)
{
    for (int i = 0; i < 31; i++)
    {
        if (x & (1LL << i))
        {
            cnt[i]--;

            if (cnt[i] == 0)
                or_sum ^= (1LL << i);
        }
    }
}

int32_t main()
{
    fio;

    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int bitMap[31] = {};

    int or_sum = x;

    // First window
    int prev = x;

    fu(bitMap, x);

    for (int i = 1; i < k; i++)
    {
        int curr = (a * prev + b) % c;

        or_sum |= curr;
        fu(bitMap, curr);

        prev = curr;
    }

    int ans = or_sum;

    int toSubtractLastElementOfWindow = x;

    // Remaining windows
    for (int i = 1; i <= n - k; i++)
    {
        int curr = (a * prev + b) % c;

        // Add new element
        or_sum |= curr;
        fu(bitMap, curr);

        // Remove old element
        fu1(bitMap, toSubtractLastElementOfWindow, or_sum);

        // Generate next outgoing element
        toSubtractLastElementOfWindow =
            (a * toSubtractLastElementOfWindow + b) % c;

        prev = curr;

        ans ^= or_sum;
    }

    cout << ans << endl;

    return 0;
}