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
 
    vector<int> freq(k + 1, 0);
 
    // Numbers from 0 to k that are currently missing
    set<int> missing;
 
    for (int i = 0; i <= k; i++)
        missing.insert(i);
 
    // First window
    for (int i = 0; i < k; i++) {
        if (a[i] <= k) {
            if (freq[a[i]] == 0)
                missing.erase(a[i]);
 
            freq[a[i]]++;
        }
    }
 
    cout << *missing.begin();
 
    // Sliding windows
    for (int i = 1; i <= n - k; i++) {
 
        // Remove old element
        int old = a[i - 1];
 
        if (old <= k) {
            freq[old]--;
 
            if (freq[old] == 0)
                missing.insert(old);
        }
 
        // Add new element
        int cur = a[i + k - 1];
 
        if (cur <= k) {
            if (freq[cur] == 0)
                missing.erase(cur);
 
            freq[cur]++;
        }
 
        // Current mex
        cout << ' ' << *missing.begin();
    }
 
    cout << '\n';
 
    return 0;
}