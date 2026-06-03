#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string countAndSay(string ans) {
    int len = ans.size();

    string str = "";
    char selected = ans[0];
    int count = 1;

    for (int i = 1; i < len; i++) {
        if (ans[i] == selected) {
            count++;
        } else {
            string cnt = to_string(count);
            str += cnt + ans[i - 1];

            selected = ans[i];
            count = 1;
        }
    }

    return str + to_string(count) + selected;
}

void solve() {
    int n;

    cin >> n;

    string ans = "1";

    for (int i = 1; i < n; i++) {
        ans = countAndSay(ans);
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