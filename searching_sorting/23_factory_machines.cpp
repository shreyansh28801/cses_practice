#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool is_feasible(long long mid, vector<long long> arr, long long threshold_product){
    long long tot_product=0;
    for(long long i:arr){
        tot_product += mid/i;
        if(tot_product>=threshold_product)return true; // we need to add this cond. otherwise overflow cases will give false output
    }
    return false;
}

void solve()
{
    long long n,t;
    cin>>n>>t;

    vector<long long> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    long long ans=-1;

    long long lo = 0;
    long long  hi ;
    long long max_elem = *max_element(arr.begin(), arr.end());
    if(max_elem > 1e18/t){
        hi=1e18;
    } else {
        hi=max_elem*t;
    }

    while((hi-lo)>1ll){
        long long mid = lo+(hi-lo)/2;
        if(is_feasible(mid, arr, t)){
            // ans=mid;
            hi=mid;
        } else {
            lo=mid+1;
        }
    }

    if(is_feasible(lo, arr, t)){
        cout<<lo<<endl;
    } else if(is_feasible(hi, arr, t)){
        cout<<hi<<endl;
    } else cout<<-1<<endl;
    
}

int main()
{
    solve();
}