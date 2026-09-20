#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}
template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}
using OMultiset = tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


    
int32_t main()
{
    fio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;


    OMultiset st;
    int inversion =0;
    for (int i = 0; i < k; i++)
    {
        int bigElelms = st.size() - st.order_of_key({a[i], i});//number of elements which are strictly gt a[i]

        inversion+=bigElelms;
        st.insert({a[i], i});
    }

    cout<<inversion<<" ";
    // cout<<"new loop"<<endl;


     for (int i = k; i < n; i++)
    {
        //remove elem
        int l = i-k;
        int smallerElems = st.order_of_key({a[l], l}); // number of elements which are strictly less than a[l]
        inversion-=smallerElems;
        st.erase({a[l], l});

        //insert new elem
        int bigElelms = st.size() - st.order_of_key({a[i], i});//number of elements which are strictly gt a[i]
        inversion+=bigElelms;
        st.insert({a[i], i});

        cout<<inversion<<" ";
    }    

    return 0;
}

// [{2,1}, {2,2} {3,1}, {}]