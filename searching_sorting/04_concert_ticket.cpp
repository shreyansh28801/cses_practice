#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> h_mst;
    vector<int> t;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        h_mst.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        t.push_back(x);
    }

    for (auto it : t)
    {
        if(h_mst.size()==0){
            cout<<"-1\n";
            continue;
        }
        auto lb = h_mst.upper_bound(it);
        if(lb == h_mst.begin() && *lb <= it){
            lb = h_mst.begin();
            cout<<*lb<<endl;
        } else if (lb != h_mst.begin()){
            cout<<*(--lb)<<endl;
        } else {cout<<"-1\n"; continue;}
        h_mst.erase(lb);
    }
}

int main()
{
    solve();
}