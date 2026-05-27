#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, k;

    cin >> n >> k;

    if (n == INT_MIN && k == -1) {
        cout << INT_MAX; 
    }

    int n1 = abs(n);
    int n2 = abs(k);

    int ans = 0;

    while (n1 >= n2) {
        int temp = n2;
        int q = 1;

        while (n1 >= temp << 1) {
            temp <<= 1;
            q <<= 1;
        }

        n1 -= temp;
        ans += q;
    }

    bool isNigga = (n < 0) ^ (k < 0);

    ans = isNigga ? 0 - ans : ans;

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