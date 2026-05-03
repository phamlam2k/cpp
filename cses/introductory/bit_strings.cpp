#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    int ans = 1;

    int MOD = 1e9 + 7;

    for (int i = 1; i <= n; i ++) {
        ans = (ans * 2) % MOD;
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