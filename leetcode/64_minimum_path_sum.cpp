#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int m, n;

    cin >> m >> n;

    vector<vector<int>> nums(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = nums[i][j];

                continue;
            }

            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + nums[i][j];

                continue;
            }

            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + nums[i][j];

                continue;
            }

            int cal = min(dp[i][j - 1], dp[i - 1][j]);

            dp[i][j] = cal + nums[i][j];
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