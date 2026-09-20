#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    // freq[x] = frequency of x in current window
    map<int, int> freq;

    // {-frequency, value}
    // begin() -> highest frequency, and smallest value on tie
    set<pair<int, int>> ordered;

    // First window
    for (int i = 0; i < k; i++) {
        int x = a[i];

        if (freq[x] > 0)
            ordered.erase({-freq[x], x});

        freq[x]++;

        ordered.insert({-freq[x], x});
    }

    cout << ordered.begin()->second;

    // Sliding window
    for (int right = k; right < n; right++) {
        int left = right - k;

        // Remove a[left]
        int x = a[left];

        ordered.erase({-freq[x], x});

        freq[x]--;

        if (freq[x] == 0) {
            freq.erase(x);
        } else {
            ordered.insert({-freq[x], x});
        }

        // Add a[right]
        x = a[right];

        if (freq[x] > 0)
            ordered.erase({-freq[x], x});

        freq[x]++;

        ordered.insert({-freq[x], x});

        cout << ' ' << ordered.begin()->second;
    }

    cout << '\n';

    return 0;
}