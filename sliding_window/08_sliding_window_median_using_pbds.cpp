#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
using OMultiset = tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

    
int32_t main()
{
    fio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;

    OMultiset st;
    for (int i = 0; i < k; i++)
    {
        st.insert({a[i], i});
    }

    if (k % 2 == 1)
    {
        cout << st.find_by_order(k / 2)->first;
    }
    else
    {
        cout << st.find_by_order((k / 2) - 1)->first;
    }
    cout << " ";
    for (int i = 1; i <= n - k; i++)
    {
        st.insert({a[i + k - 1], i + k - 1});
        st.erase({a[i - 1], i - 1});
        if (k % 2 == 1)
        {
            cout << st.find_by_order(k / 2)->first;
        }
        else
        {
            cout << st.find_by_order((k / 2) - 1)->first;
        }
        cout << " ";
    }

    return 0;
}