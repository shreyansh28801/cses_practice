#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

bool isPossible(vector<ll> arr, ll threshold, ll k){
    int ct=1;
    ll cur=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>threshold)return false;
        cur+=arr[i];
        if(cur > threshold){
            cur=arr[i];
            ct++;
        }
    }
    return ct<=k;
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<ll> arr;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    long long lo = 1, hi = 1e16;

    while((hi-lo)>1){
        ll mid = lo + (hi-lo)/2;
        if(isPossible(arr, mid, k)){
            hi=mid;
        } else lo=mid+1;
    }
    if(isPossible(arr, lo, k)){
        cout<<lo;
    } else if(isPossible(arr, hi, k)){
        cout<<hi;
    } else cout<<-1;
}

int main()
{
    solve();
}
