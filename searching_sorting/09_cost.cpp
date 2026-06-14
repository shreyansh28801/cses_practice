#include <iostream>
#include <algorithm>
#include <vector>
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

    sort(v.begin(), v.end());

    long long cost = 0ll;
    for (auto i : v)
    {
        cost += (abs(i - v[n / 2]));
    }
    cout << cost << endl;
}

int main()
{
    solve();
}