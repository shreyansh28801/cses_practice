#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool static compareInterval(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movie_interval;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        movie_interval.push_back({x, y});
    }
    sort(movie_interval.begin(), movie_interval.end(), compareInterval);

    int ans = 1;
    int i = 1;
    int last = movie_interval[0].second;

    while (i < n)
    {
        if (movie_interval[i].first >= last)
        {
            ans++;
            last = movie_interval[i].second;
        }
        i++;
    }
    cout << ans;
}

int main()
{
    solve();
}