#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i + 1);
    }

    for (auto it : mp)
    {
        if (mp.find(x - it.first) != mp.end())
        {
            if (x - it.first == it.first)
            {
                if (it.second.size() > 1)
                {
                    cout << it.second[0] << " " << it.second[1] << endl;
                    return;
                }
            }
            else
            {
                cout << it.second[0] << " " << mp[x - it.first][0] << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    solve();
}