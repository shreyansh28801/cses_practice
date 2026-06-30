#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

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

    vector<int> pref_max(n);
    pref_max[0] = vpr[0][1];
    for (int i = 1; i < n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], vpr[i][1]);
    }

    vector<int> suf_min(n);
    suf_min[n - 1] = vpr[n - 1][1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf_min[i] = min(suf_min[i + 1], vpr[i][1]);
    }

    vector<pair<int, int>> v_contain_oth(n), v_oth_contain(n);

    for (int i = n - 1; i > 0; i--)
    { // v_oth_contain
        if (pref_max[i - 1] >= vpr[i][1])
            v_oth_contain[i] = {vpr[i][2], 1};
        else
            v_oth_contain[i] = {vpr[i][2], 0};
    }
    v_oth_contain[0] = {vpr[0][2], 0};

    for (int i = 0; i < n - 1; i++)
    { // v_contain_oth
        if (suf_min[i + 1] <= vpr[i][1])
            v_contain_oth[i] = {vpr[i][2], 1};
        else
            v_contain_oth[i] = {vpr[i][2], 0};
    }
    v_contain_oth[n - 1] = {vpr[n - 1][2], 0};

    // for(auto i:v_contain_oth){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // cout<<endl;

    sort(v_oth_contain.begin(), v_oth_contain.end());
    sort(v_contain_oth.begin(), v_contain_oth.end());

    for (auto i : v_contain_oth)
        cout << i.second << " ";
    cout << endl;
    for (auto i : v_oth_contain)
        cout << i.second << " ";
    cout << endl;
}

int main()
{
    solve();
}
