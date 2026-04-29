#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void dequy(int num) {
    cout << num << " ";

    if (num == 1) return;

    if (num % 2 == 0) {
        dequy(num / 2);
    } else {
        dequy(num * 3 + 1);
    }
}

void solve() {
    int n;

    cin >> n;

    dequy(n);
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}