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
 
void fu(vector<int> &bitMap, int a)
{
    int i = 0;
    while (i < 31 && (a & (1 << i)) != 0)
    {
        bitMap[i]++;
        i++;
    }
    return;
}
 
void fu1(vector<int> &bitMap, int toSubtractLastElementOfWindow, int &or_sum)
{
    int i = 0;
    while (i < 31)
    {
        if ((bitMap[i] == 1) && ((toSubtractLastElementOfWindow & (1 << i)) != 0))
        {
            or_sum ^= (1 << i);
        }
        if ((toSubtractLastElementOfWindow & (1 << i)) != 0)
            bitMap[i]--;
        i++;
    }
    return;
}
 
int32_t main()
{
    fio;
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
 
    vector<int> bitMap(32, 0);
    int or_sum = x;
    // first window;
    int prev = x;
    fu(bitMap, x);
    for (int i = 1; i < k; i++)
    {
        int curr = (a * prev + b) % c;
        or_sum |= curr;
        fu(bitMap, curr);
        prev = curr;
    }
    int ans = 0;
    ans = or_sum;
    // cout<<sum<<" "<<endl;
    int toSubtractLastElementOfWindow = x;
    for (int i = 1; i <= n - k; i++)
    {
        int curr = (a * prev + b) % c;
        or_sum |= curr;
        fu(bitMap, curr);
        fu1(bitMap, toSubtractLastElementOfWindow, or_sum);
 
        toSubtractLastElementOfWindow = (a * toSubtractLastElementOfWindow + b) % c;
        // cout<<sum<<" ";
        prev = curr;
        ans = ans ^ or_sum;
    }
    cout << ans << endl;
 
    return 0;
}