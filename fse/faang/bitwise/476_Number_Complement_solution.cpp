#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int num;

    cin >> num;

    int temp = num;
    int mask = 0;

    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    num = num ^ mask;

    cout << num;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}