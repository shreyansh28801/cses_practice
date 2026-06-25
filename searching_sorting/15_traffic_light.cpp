#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve()
{
    long long n,x;
    cin >>x>>n;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    
    set<int> cur_pos;
    cur_pos.insert(0);
    cur_pos.insert(x);
    // long long ans1 = n;
    // long long ans2 =INT_MIN;
    vector<int> ans;
    multiset<int> cur_mx;
    cur_mx.insert(x);
    for (int i = 0; i < n; i++)
    {
        auto it_pos = cur_pos.upper_bound(v[i]);//ln
        int a=*it_pos;
        int b=*--it_pos;
        int curSeg = a-b; //8 -> (0,3) (3,8)
        auto it= cur_mx.lower_bound(curSeg);//ln
        cur_mx.erase(it);//ln
        cur_mx.insert(a-v[i]);//ln
        cur_mx.insert(v[i]-b);//ln
        cur_pos.insert(v[i]);//ln
        ans.push_back(*--cur_mx.end());
    }
    for(auto it:ans){
        cout<<it<<" ";
    }

}

int main()
{
    solve();
}


// 100 96 99 98 97 95 96 


// 100 66
// 19 18 17 15 


// 100 19 18 17 15 7
// 66

//25 27 15 24 24 24

// 25 ... 15
// 27 24
// 24
// 24

// 25  24
// 27 24
//  ...
// 15 
// 24

