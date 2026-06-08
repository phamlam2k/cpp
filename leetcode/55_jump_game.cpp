#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;
    
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxReach = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            cout << "false";
            return;
        }

        maxReach = max(maxReach, i + arr[i]);

        if (maxReach >= n - 1) {
            cout << "true";
            return;
        }
    }

    cout << "true";
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}