#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool static cmp(vector<int> p1, vector<int> p2)
{
    if (p1[0] == p2[0])
    {
        return p1[1] > p2[1];
    }
    return p1[0] < p2[0];
}

void solve()
{
    long long n;
    cin >> n;
    vector<vector<int>> vpr;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vpr.push_back({x, y, i}); // first, second, index
    }
    sort(vpr.begin(), vpr.end(), cmp);

    ordered_multiset<int> ost;
   

    vector<int> v_contain_oth(n,0), v_oth_contain(n,0);

    for (int i = n - 1; i >= 0; i--)
    { // v_contain_oth
        int ub = ost.order_of_key(vpr[i][1]+1);
        v_contain_oth[vpr[i][2]]=ub;
        ost.insert(vpr[i][1]);
    }
    ost.clear();

    for (int i = 0; i < n ; i++)
    { // v_oth_contain
        int lb = ost.order_of_key(vpr[i][1]);
        v_oth_contain[vpr[i][2]]=i-lb;
        ost.insert(vpr[i][1]);
    }

    // for(auto i:v_contain_oth){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout<<endl;


    for (auto i : v_contain_oth)
        cout << i << " ";
    cout << endl;
    for (auto i : v_oth_contain)
        cout << i << " ";
    cout << endl;
}

int main()
{
    solve();
}
