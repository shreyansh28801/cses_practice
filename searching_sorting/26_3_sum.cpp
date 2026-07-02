#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, val;
    cin >> n >> val;
    vector<vector<long long>> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back({x, i+1});
    }

    sort(arr.begin(), arr.end());


    for(int i=0;i<n;i++){
        int lo=i+1;
        int hi=n-1;
        int target=val-arr[i][0];

        while(lo < hi){
            if((arr[lo][0]+arr[hi][0])>target)hi--;
            else if((arr[lo][0]+arr[hi][0])<target)lo++;
            else {
                vector<int> ret;
                ret.push_back(arr[i][1]);
                ret.push_back(arr[lo][1]);
                ret.push_back(arr[hi][1]);
                sort(ret.begin(), ret.end());
                for(auto it:ret)cout<<it<<" ";
                return;
            }
        }
    }

    cout<<"IMPOSSIBLE";
}

int main()
{
    solve();
}