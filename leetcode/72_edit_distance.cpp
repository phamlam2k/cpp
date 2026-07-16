#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string word1, word2;

    cin >> word1 >> word2;

    int len1 = word1.length();
    int len2 = word2.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len2; i++) dp[0][i] = i;
    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] != word2[j - 1]) {
                dp[i][j] = 1 + min({
                    dp[i - 1][j - 1],
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    cout << dp[len1][len2];
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}