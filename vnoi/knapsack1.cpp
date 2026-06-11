#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void init(vector<vector<int>> &dp, int &n, int &k) {
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= k; i++) {
        dp[i][0] = 0;
    }
}

void solve() {
    int n, k;

    cin >> k >> n;

    vector<pair<int, int>> arr(k + 1); 
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; i++) {
        int u, v;

        cin >> u >> v;

        arr[i] = { u, v };
    }

    init(dp, n, k);

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= arr[i].first) {
                int val = max(dp[i][j], arr[i].second + dp[i - 1][j - arr[i].first]);
    
                dp[i][j] = max(dp[i][j - 1], val);
            }

        }
    }

    cout << dp[k][n];
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}