#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str;

    cin >> str;

    int len = str.length();

    int left = 0;
    int right = 0;
    int ans = 0;

    for (int i = 0; i < len; i++) {
        if (right == left) {
            ans = max(ans, right + left);
        }

        if (right > left) {
            left = 0;
            right = 0;
        }

        if (str[i] == '(') {
            left++;   
        } else {
            right++;
        }
    }

    left = 0;
    right = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (right == left) {
            ans = max(ans, right + left);
        }

        if (right < left) {
            left = 0;
            right = 0;
        }

        if (str[i] == '(') {
            left++;   
        } else {
            right++;
        }
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