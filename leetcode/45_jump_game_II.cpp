// TODO: This is a brute force solution. We can optimize it by using a greedy approach.
#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool moveon (vector<int> &arr, vector<int> &trace, int &ans, int n, int idx) {
    if (idx == n - 1) {
        int len = trace.size();
        ans = min(ans, len);
        
        return true;
    }

    if (idx > n - 1 || arr[idx] == 0) {
        return false;
    }

    int start = min(n - 1, arr[idx]);

    for (int i = start; i > 0; i--) {
        trace.push_back(arr[idx]);

        bool checked = moveon(arr, trace, ans, n, idx + i);

        if (checked) {
            return true;
        }

        trace.pop_back();
    }

    return true;
}

void solve() {
    int n;
    
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = INT_MAX;

    vector<int> trace;

    moveon(arr, trace, ans, n, 0);

    if (ans == INT_MAX) {
        cout << 0;
        return;
    }

    cout << ans;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}