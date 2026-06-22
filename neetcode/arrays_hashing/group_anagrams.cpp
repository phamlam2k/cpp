#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    map<string, vector<string>> mp;

    for (int i = 0; i < n; i++) {
        string key = string(26, '0');
        int len = strs[i].length();
        
        for (int j = 0; j < len; j++) {
            int idx = strs[i][j] - 'a';

            key[idx]++;
        }

        mp[key].push_back(strs[i]);
    }

    vector<vector<string>> ans;

    for (const auto& [key, value]: mp) {
        ans.push_back(mp[key]);
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j ++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}