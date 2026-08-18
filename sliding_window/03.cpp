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
int32_t main()
{
    fio;
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
 
    int sum = 0;
    // first window;
    int prev = x;
    sum = x;
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        int curr = (a * prev + b) % c;
        sum ^= curr;
        prev = curr;
    }
    ans = sum;
    // cout<<sum<<" "<<endl;
    int toSubtractLastElementOfWindow = x;
    for (int i = 1; i <= n - k; i++)
    {
        int curr = (a * prev + b) % c;
        sum ^= curr;
        sum ^= toSubtractLastElementOfWindow;
        toSubtractLastElementOfWindow = (a * toSubtractLastElementOfWindow + b) % c;
        // cout<<sum<<" ";
        prev = curr;
        ans = ans ^ sum;
    }
    cout << ans << endl;
 
    return 0;
}