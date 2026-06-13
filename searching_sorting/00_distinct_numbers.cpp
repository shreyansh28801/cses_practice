#include <iostream>
#include <set>
using namespace std;


void solve() {
    int n;
    cin>>n;
    set<int> st;

    while(n--){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size();
}

int main() {
    solve();
}