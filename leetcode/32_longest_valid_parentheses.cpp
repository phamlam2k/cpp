#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str = "";

    cin >> str;

    int mx = 0;
    int left = 0;
    int right = 0;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            left++;
        } else {
            right++;

            if (right == left) {
                mx = max(mx, right * 2);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
    }

    left = 0;
    right = 0;

    for (int i = len - 1; i > 0; i--) {
        if (str[i] == ')') {
            left++;
        } else {
            right++;

            if (right == left) {
                mx = max(mx, right * 2);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
    }

    cout << mx;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}