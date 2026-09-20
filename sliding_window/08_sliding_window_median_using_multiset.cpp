#include <bits/stdc++.h>
using namespace std;
 
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
 
    // Functionality for first window
    for (int i = 0; i < k; i++) {
        low.insert(a[i]);
    }
 
    // Move largest elements to high
    while ((int)low.size() > need) {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
 
    cout << *low.rbegin();
 
    // Sliding window
    for (int i = 1; i <= n - k; i++) {
 
        // Remove outgoing element
        int old = a[i - 1];
 
        auto it = low.find(old);
 
        if (it != low.end()) {
            low.erase(it);
        } else {
            it = high.find(old);
            high.erase(it);
        }
 
        // Add incoming element
        int cur = a[i + k - 1];
 
        if (!low.empty() && cur <= *low.rbegin()) {
            low.insert(cur);
        } else {
            high.insert(cur);
        }
 
        // Balance sizes
        while ((int)low.size() < need) {
            auto it2 = high.begin();
            low.insert(*it2);
            high.erase(it2);
        }
 
        while ((int)low.size() > need) {
            auto it2 = prev(low.end());
            high.insert(*it2);
            low.erase(it2);
        }
 
        cout << " " << *low.rbegin();
    }
 
    cout << '\n';
 
    return 0;
}