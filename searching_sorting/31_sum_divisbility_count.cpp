#include <iostream>
#include <vector>
#include <map>
using namespace std;

int modOfNumber(long long num, int M){
    if(num<0){
        return ((num%M)+M)%M;
    }
    return num%M;
}

void solve()
{
    long long n;
    cin >> n ;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    map<long long, int> mp;

    long long ans=0;
    long long curSum=0;
    mp[0]=1;

    for(int i=0;i<n;i++){
        curSum+=arr[i];
        if(mp.find(modOfNumber(curSum, n))!=mp.end()){
            ans+=mp[modOfNumber(curSum, n)];
        }
        mp[modOfNumber(curSum, n)]++;
    }

    cout<<ans;
}

int main()
{
    solve();
}