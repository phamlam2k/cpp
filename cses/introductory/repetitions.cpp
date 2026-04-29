#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str;

    cin >> str;

    queue<char> q;

    int ans = 0;
    int len = str.length();

    q.push(str[0]);

    for (int i = 1; i < len; i++) {
        char front_char = q.front();

        if (front_char != str[i]) {
            int cnt = 0;

            while (!q.empty()) {
                cnt++;

                q.pop();    
            }

            ans = max(ans, cnt);
        }

        q.push(str[i]);
    }

    int cnt = 0;

    while (!q.empty()) {
        cnt++;

        q.pop();
    }

    ans = max(ans, cnt);

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