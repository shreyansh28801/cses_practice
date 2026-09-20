#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int, int> freq;
    int distinct = 0;

    // First window
    for (int i = 0; i < k; i++) {
        if (freq[a[i]] == 0)
            distinct++;

        freq[a[i]]++;
    }

    cout << distinct << " ";

    // Slide the window
    for (int right = k; right < n; right++) {
        int left = right - k;

        // Add a[right]
        if (freq[a[right]] == 0)
            distinct++;

        freq[a[right]]++;

        // Remove a[left]
        freq[a[left]]--;

        if (freq[a[left]] == 0)
            distinct--;

        cout << distinct << " ";
    }

    cout << '\n';

    return 0;
}