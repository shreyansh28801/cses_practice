#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve()
{
    int n;
    cin >> n ;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    stack<int> st;
    vector<int> ret(n);

    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ret[i]=0;
        } else {
            ret[i]=st.top()+1;
        }
        st.push(i);
    }

    for(auto it:ret)cout<<it<<" ";
    cout<<endl;

}

int main()
{
    solve();
}