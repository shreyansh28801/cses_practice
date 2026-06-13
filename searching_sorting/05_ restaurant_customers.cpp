#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a,d;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        d.push_back(y);
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    int l=0, r=0;
    int cur_ans=0;
    int mx_ans=0;

    while(l<n && r<n){
        if(a[l]<d[r]){
            cur_ans++;
            mx_ans=max(cur_ans, mx_ans);
            l++;
        } else {
            cur_ans--;
            r++;
        }
    }

    cout<<mx_ans;
    
}

int main()
{
    solve();
}