#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int flipBit(int x, int k) {
    return x ^ (1 << k);
}

void solve() {
    int num;

    cin >> num;

    int temp = num;
    int count = 0;

    while (temp) {
        num = flipBit(num, count);
        count++;
        temp >>= 1;
    }

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