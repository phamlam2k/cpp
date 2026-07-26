#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int left = 0;
    int right = n - 1;
    int max_area = 0;

    while (left < right) {
        int minH = min(height[left], height[right]);

        max_area = max(max_area, minH * (right - left));

        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_area;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}