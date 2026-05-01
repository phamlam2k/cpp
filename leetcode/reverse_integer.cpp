#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int x;

    cin >> x;

    int ans = 0;

    while (x) {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }

    if (ans < INT_MIN || ans > INT_MAX) {
        cout << 0;
    } else {
        cout << ans;
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