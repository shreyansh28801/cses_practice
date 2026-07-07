#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;

    vector<long long> arr;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        arr.push_back(x);
    }
    vector<long long> prefix(n+1);
    prefix[0]=0;
    long long ans = -1 * 1e18;

    multiset<long long> mst;

    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
        if(i<a)continue;
        mst.insert(prefix[i-a]);
        if(i>b)mst.erase(mst.lower_bound(prefix[i-b-1]));
        ans = max(ans, prefix[i]-(long long)*mst.begin());
    }
    cout<<ans;
}


int main()
{
    solve();
}