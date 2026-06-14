#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    long long mx_sum=INT_MIN;
    long long cur_sum_so_far=0;
    
    for(int i:v) {
        cur_sum_so_far+=i;
        if(mx_sum<cur_sum_so_far){
            mx_sum=cur_sum_so_far;
        }
        if(cur_sum_so_far<0)cur_sum_so_far=0;
    }
    cout<<mx_sum<<endl;
}

int main()
{
    solve();
}