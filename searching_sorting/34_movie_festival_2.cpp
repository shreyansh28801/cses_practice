#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;

        v.push_back({e,s});
    }

    sort(v.begin(), v.end());

    multiset<int> ets; //set of end time that are processed so far
    ets.insert(v[0][0]);
    int ct=0;


    for(int i=1;i<n;i++){
        auto it=ets.upper_bound(v[i][1]);
        if(it==ets.begin()){
            if(ets.size()>=k){
                continue;
            } else {
                ets.insert(v[i][0]);
                ct++;
            }
        } else {
            it--;
            ets.erase(it);
            ets.insert(v[i][0]);
            ct++;
        }
    }
    cout<<ct+1;
}

int main(){
    solve();
}