#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

map<char, bool> mp;

void init () {
    mp.insert(make_pair('a', true));
    mp.insert(make_pair('o', true));
    mp.insert(make_pair('y', true));
    mp.insert(make_pair('e', true));
    mp.insert(make_pair('u', true));
    mp.insert(make_pair('i', true));
}

void solve() {
    init();

    string str;

    cin >> str;

    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });

    int len = str.length();

    queue<char> q2;

    for(int i = 0; i < len; i++) {
        if (!mp[str[i]]) {
            q2.push(str[i]);
        }
    }

    string ans = "";

    while (!q2.empty()) {
        ans += '.';
        ans += q2.front();

        q2.pop();
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