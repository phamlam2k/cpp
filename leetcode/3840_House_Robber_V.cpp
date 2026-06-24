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
    int n;

    cin >> n;

    vector<int> nums(n);
    vector<int> colors(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> dp(n);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        if (colors[i] != colors[i - 1]) {
            dp[i] = nums[i] + dp[i - 1];
        } else {
            if (i > 1) {
                int sum = nums[i] + dp[i - 2];

                dp[i] = max(sum, dp[i - 1]);
            } else {
                dp[i] = max(nums[i], dp[i - 1]);
            }
        }
    }

    cout << dp[n - 1];
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}