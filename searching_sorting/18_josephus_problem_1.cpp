#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 1 2 3
// 1 2 3 4
vector<int> fun(int n){
    if(n==1)return {1};

    vector<int> v;
    for(int i=2;i<=n;i+=2){ // first round consideration
        v.push_back(i);
    }

    vector<int> rem_elms;
    if(n%2){
        rem_elms.push_back(n);
        for(int i=1;i<n;i+=2){
            rem_elms.push_back(i);
        }
    } else {
        for(int i=1;i<n;i+=2){
            rem_elms.push_back(i);
        }
    }

    vector<int> temp = n%2 ? fun(n/2+1): fun(n/2);
    for(auto it:temp){
        v.push_back(rem_elms[it-1]);
    }
    return v;
}

void solve() {
    int n;
    cin>>n;
    
    vector<int>v = fun(n);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    solve();
}