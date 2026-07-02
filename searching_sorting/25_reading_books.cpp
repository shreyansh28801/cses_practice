#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> arr;
    long long sum = 0ll;
    for (int i = 0; i < n; i++)
    {
        long long dur;
        cin >> dur;
        arr.push_back(dur);
        sum += dur;
    }

    sort(arr.begin(), arr.end());

    if((sum-arr.back())<arr.back()){
        cout<<2*arr.back();
    } else cout<<sum;

}

int main()
{
    solve();
}