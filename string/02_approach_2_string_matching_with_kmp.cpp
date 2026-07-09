#include <iostream>
#include <vector>
#include <string>
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
    string a, b;
    cin >> a >> b;
    string str = b+"$"+a;
    vector<int> lps = build_lps(str);
    int n=a.size(), m=b.size();
    int ct=0;
    for(int i=m+1;i<str.size();i++){
        if(lps[i]==m)ct++;
    }

    cout << ct;
}

int main()
{
    solve();
    return 0;
}