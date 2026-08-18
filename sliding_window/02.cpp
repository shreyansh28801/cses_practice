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

    deque<int> dq;
    int i, j;
    i = 0, j = 0;

    int prev=-1; // demnotes very starting
    int toSubtractLastElementOfWindow = x;
    int ans = 0;
    while (j < n)
    {
        int cur = prev==-1?x:((a*prev+b)%c);
        while (dq.size() > 0 && dq.back() > cur) // Remove all elements which are smaller than a[j]
                                                  // (and appear before a[j] (since it is present in
                                                  // dequeue hence must have appeared before a[j]))
                                                  // (As they can't be answer);
            dq.pop_back();

        dq.push_back(cur);
        prev = cur;

        if (j - i + 1 < k){
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans ^= dq.front();
            if (dq.size() > 0 &&
                toSubtractLastElementOfWindow  == dq.front()) // Since we are about to shift this
                                    // window (fixed size hence i++,j++)
                                    // (Hence if dq.back()==a[i] that needs
                                    // to be popped out from dq);
                dq.pop_front();
            i++;
            j++;
            toSubtractLastElementOfWindow =  (a * toSubtractLastElementOfWindow + b) % c;;
        }
    }

    cout << ans << endl;
 
    return 0;
}


