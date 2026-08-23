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

void add(int cnt[], int x, int &or_sum)
{
    while (x)
    {
        int bit = __builtin_ctzll(x);

        cnt[bit]++;
        or_sum |= (1LL << bit);

        x &= (x - 1);
    }
}

void removeElement(int cnt[], int x, int &or_sum)
{
    while (x)
    {
        int bit = __builtin_ctzll(x);

        cnt[bit]--;

        if (cnt[bit] == 0)
            or_sum ^= (1LL << bit);

        x &= (x - 1);
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

    int or_sum = 0;

    // First window
    int prev = x;

    add(bitMap, x, or_sum);

    for (int i = 1; i < k; i++)
    {
        int curr = (a * prev + b) % c;

        add(bitMap, curr, or_sum);

        prev = curr;
    }

    int ans = or_sum;

    int toSubtractLastElementOfWindow = x;

    // Remaining windows
    for (int i = k; i < n; i++)
    {
        int curr = (a * prev + b) % c;

        // Add new element
        add(bitMap, curr, or_sum);

        // Remove old element
        removeElement(bitMap, toSubtractLastElementOfWindow, or_sum);

        // Generate next outgoing element
        toSubtractLastElementOfWindow =
            (a * toSubtractLastElementOfWindow + b) % c;

        prev = curr;

        ans ^= or_sum;
    }

    cout << ans << endl;

    return 0;
}