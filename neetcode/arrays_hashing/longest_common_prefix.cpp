#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string prefix_strs (string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int len = min(len1, len2);

    string ans = "";

    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i]) {
            return ans;
        }

        ans += str1[i];
    }

    return ans;
}

void solve() {
    int n;

    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string prefix = prefix_strs(strs[0], strs[1]);

    for (int i = 2; i < n; i++) {
        prefix = prefix_strs(prefix, strs[i]);
    }

    cout << prefix;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}