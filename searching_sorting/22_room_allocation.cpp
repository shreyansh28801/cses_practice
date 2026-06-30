#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> a,d;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({x,i});
        d.push_back({y,i});
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    int l=0, r=0;
    int ans=0;
    set<int> room_occupied;
    set<int> room_vacant;
    vector<int> ret(n);

    while(l<n && r<n){
        if(a[l][0]<=d[r][0]){
            if(room_vacant.empty()){
                ret[a[l][1]]=(int)room_occupied.size()+1;
                room_occupied.insert((int)room_occupied.size()+1);
            } else {
                ret[a[l][1]]=(int)*room_vacant.begin();
                room_occupied.insert(*room_vacant.begin());
                room_vacant.erase(room_vacant.begin());
            }
            ans = max(ans, (int)room_occupied.size());
            l++;
        } else {
            room_vacant.insert(ret[d[r][1]]);
            room_occupied.erase(ret[d[r][1]]);
            r++;
        }
    }

    cout<<ans<<endl;
    for(auto i:ret)cout<<i<<" ";
    cout<<endl;

    
}

int main()
{
    solve();
}