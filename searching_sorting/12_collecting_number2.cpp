#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void process_m_queries(vector<long long> &v, unordered_map<int, int> &pos, int round, int m){
    while(m--){
        int i,j;
        cin>>i>>j;
        if(i>j)swap(i, j);//in swaping the result would be same either ways i.e. swapping i to j or j to i will lead to same result.

        int x, y;
        x=v[i-1];
        y=v[j-1];
        i--;
        j--;
        if(pos[x+1]>i && pos[x+1]<j)round++;
        if(pos[x-1]>i && pos[x-1]<j)round--;
        if(pos[y+1]>i && pos[y+1]<j)round--;
        if(pos[y-1]>i && pos[y-1]<j)round++;

        // cout<<"till now round "<<round;
        // cout<<" i and j , x & y are "<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<pos[x+1]
        // <<" "<<pos[y-1]<<endl;
        //case when elements are consecutive
        if(x==(y+1))round--;
        if(x==(y-1))round++;
        //  cout<<" till now round "<<round<<" final is ";
        
        cout<<round<<endl;


        swap(v[i], v[j]);
        pos[x]=j;
        pos[y]=i;
    }
}

void solve()
{
    long long n,m;
    cin >> n>>m;
    vector<long long> v;
    unordered_map<int, int> pos;
    pos[0]=0;
    pos[n+1]=n+1;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
        pos[x]=i;
    }

    int last = n;
    int ans=0;

    while(true){
        if(last<=0)break;
        while(pos[last]>pos[last-1]){
            last-=1;
        }
        ans++;
        last-=1;
    }
   
    process_m_queries(v, pos, ans, m);

}

int main()
{
    solve();
}

// 2 4 1 5 3