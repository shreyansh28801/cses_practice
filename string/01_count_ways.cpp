#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

int M = 1e9 + 7;

vector<int> cache;

int fu(int idx, string &str, unordered_set<string> &ust)
{
    if (idx >= str.size())
        return 1;
    if(cache[idx]!=-1)return cache[idx];
    string temp;
    int ans = 0;
    for (int i = idx; i < str.size(); i++)
    {
        temp.push_back(str[i]);
        if (ust.find(temp) != ust.end())
        {
            ans = (ans + fu(i + 1, str, ust)) % M;
        }
    }
    return cache[idx] = ans;
}

void solve()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    unordered_set<string> ust;
    while (k--)
    {
        string s;
        cin >> s;
        ust.insert(s);
    }
    cache.resize(str.size()+1, -1);
    cout << fu(0, str, ust);
}

int main()
{
    solve();
    return 0;
}