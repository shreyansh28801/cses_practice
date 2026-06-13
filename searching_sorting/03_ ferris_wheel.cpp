#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, x;
    cin>>n>>x;

    vector<int> w;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        w.push_back(x);
    }

    sort(w.begin(), w.end());

    int l=0, r=n-1;
    int ans=0;
    while(l<=r){
        if((w[l]+w[r])<=x){
            l++;
            r--;
            ans++;
        } else {
            r--;
            ans++;
        }
    }
    cout<<ans;
}

int main()
{
    solve();
}
