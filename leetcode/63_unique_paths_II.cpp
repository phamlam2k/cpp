#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int m, n;

    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    if (obstacleGrid[0][0] == 1) {
        cout << 0;

        return;
    }

    vector<vector<int>> dp(m, vector<int> (n));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;

                continue;
            }

            if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j - 1];

                continue;
            }

            if (j == 0 && i > 0) {
                dp[i][j] = dp[i - 1][j];

                continue;
            }

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }    

    cout << dp[m - 1][n - 1];
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}