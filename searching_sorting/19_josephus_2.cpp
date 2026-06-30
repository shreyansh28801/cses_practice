#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    ordered_set<int> s;

    for (int i = 1; i <= n; i++)
        s.insert(i);

    long long idx = 0;

    while (!s.empty()) {

        idx = (idx + k) % s.size();

        auto it = s.find_by_order(idx);// this is special operation of ordered set that is only supported in cpp lang. aka pbds

        cout << *it << " ";

        s.erase(it);
    }

    return 0;
}