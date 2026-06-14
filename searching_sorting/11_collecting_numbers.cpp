#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> v;
    map<int, int> mp;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
        mp[x]=i;
    }


    int last = n;
    int ans=0;

    while(true){
        if(last<=0)break;
        while(mp[last]>mp[last-1]){
            last-=1;
        }
        ans++;
        last-=1;
    }

    cout<<ans;

}

int main()
{
    solve();
}

// 2 4 1 5 3