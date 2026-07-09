#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> build_lps(string &str){
    int n=str.size();
    vector<int> lps(n);
    lps[0]=0;
 
    int i=1;
    int len = 0;
    while (i<n)
    {
        if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
        } else {
            if(len>0){
                len = lps[len-1];
            } else {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
 
void solve()
{
    string a;
    cin >> a;
    vector<int> lps = build_lps(a);
    int n=a.size();
    vector<int> v;
    int i=n-1;
    while(i>=0 && lps[i]>0){
        v.push_back(lps[i]);
        i=lps[i]-1;
    }
 
    for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";
}
 
int main()
{
    solve();
    return 0;
}