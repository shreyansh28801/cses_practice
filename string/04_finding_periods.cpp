#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 //abcabcabc
 //0000300
 //000600
//  z[6]=???

vector<int> build_z_array(string &s) {
    int n = s.size();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {

        // i lies inside the current Z-box
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        // Try to extend the match
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        // Update the Z-box if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}
 
void solve()
{
    string a;
    cin >> a;
    vector<int> z = build_z_array(a);
    int n=a.size();
    vector<int> v;
    
    for (int i = 1; i < n; i++)
    {
        int p = i;//period length
        if(z[i]==n-p){
            v.push_back(p);
        }
    }

    v.push_back(n);
 
    for(int i:v)cout<<i<<" ";
}
 
int main()
{
    solve();
    return 0;
}