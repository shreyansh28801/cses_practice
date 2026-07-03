#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    map<long long, int> mp;

    int ans=0;
    long long curSum=0;
    mp[0]=1;

    for(int i=0;i<n;i++){
        curSum+=arr[i];
        if(mp.find(curSum-x)!=mp.end()){
            ans++;
        }
        mp[curSum]++;
    }

    cout<<ans;
}

int main()
{
    solve();
}