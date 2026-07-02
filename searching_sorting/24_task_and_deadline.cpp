#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<vector<long long>> arr;
    for (int i = 0; i < n; i++)
    {
        long long dur, dl;
        cin>>dur>>dl;
        arr.push_back({dur, dl});
    }

    sort(arr.begin(), arr.end());
    long long tot=0ll;
    long long cur_time=0;
    for(auto it:arr){
        long long dur=it[0];
        long long dl=it[1];
        long long finish_time = cur_time+dur;
        tot+=(dl-finish_time);
        cur_time+=dur;
    }
    cout<<tot<<endl;

    //Note : how to solve the problem when the reward is considered only its positive value ???
}

int main()
{
    solve();
}