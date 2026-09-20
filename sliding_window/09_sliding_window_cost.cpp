#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

//extension of previous question
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    multiset<int> low, high;
 
    // low should contain (k+1)/2 elements
    int need = (k + 1) / 2;
 
    // Sum of elements in low and high
    ll sumLow = 0, sumHigh = 0;
 
    // First window
    for (int i = 0; i < k; i++) {
        low.insert(a[i]);
        sumLow += a[i];
    }
 
    // Move largest elements to high
    while ((int)low.size() > need) {
 
        auto it = prev(low.end());
 
        sumHigh += *it;
        high.insert(*it);
 
        sumLow -= *it;
        low.erase(it);
    }
 
    // Calculate cost of current window
    ll median = *low.rbegin();
 
    ll cost =
        median * (ll)low.size() - sumLow
        + sumHigh - median * (ll)high.size();
 
    cout << cost;
 
    // Sliding window
    for (int i = 1; i <= n - k; i++) {
 
        // Remove outgoing element
        int old = a[i - 1];
 
        auto it = low.find(old);
 
        if (it != low.end()) {
 
            low.erase(it);
            sumLow -= old;
 
        } else {
 
            it = high.find(old);
            high.erase(it);
            sumHigh -= old;
        }
 
        // Add incoming element
        int cur = a[i + k - 1];
 
        if (!low.empty() && cur <= *low.rbegin()) {
 
            low.insert(cur);
            sumLow += cur;
 
        } else {
 
            high.insert(cur);
            sumHigh += cur;
        }
 
        // Balance sizes
        while ((int)low.size() < need) {
 
            auto it2 = high.begin();
 
            low.insert(*it2);
            sumLow += *it2;
 
            sumHigh -= *it2;
            high.erase(it2);
        }
 
        while ((int)low.size() > need) {
 
            auto it2 = prev(low.end());
 
            high.insert(*it2);
            sumHigh += *it2;
 
            sumLow -= *it2;
            low.erase(it2);
        }
 
        // Median
        median = *low.rbegin();
 
        // Cost
        cost =
            median * (ll)low.size() - sumLow
            + sumHigh - median * (ll)high.size();
 
        cout << " " << cost;
    }
 
    cout << '\n';
 
    return 0;
}