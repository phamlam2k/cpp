#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < n; i++) {
        string key = string(26, '0');
        string str = arr[i];

        for (char &c: str) {
            key[c - 'a']++;
        }

        mp[key].push_back(str);
    }

    vector<vector<string>> ans;

    for (auto &m: mp) {
        ans.push_back(move(m.second));
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