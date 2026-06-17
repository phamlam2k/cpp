#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    double x;
    int n;

    cin >> x >> n;

    int N = n;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double current = x;
    double ans = 1.0;

    while (N > 0) {
        if (N % 2 == 1) {
            ans *= current;
        }

        current *= current;
        N /= 2;
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