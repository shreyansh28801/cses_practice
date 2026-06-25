#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> top;

    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(top.begin(), top.end(), v[i]);
        if(it==top.end()){
            top.push_back(v[i]);
        } else {
            *it = v[i];
        }

    }

    cout<<top.size();

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

