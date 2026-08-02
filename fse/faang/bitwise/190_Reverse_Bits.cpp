#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int flipBit(int x,int k) {
    return x ^ (1 << k);
}

int getBit(int x, int k) {
    return (x >> k) & 1;
}

void solve() {
    int n;

    cin >> n;

    int left = 0;
    int right = 31;

    while (left < right) {
        int leftBit = getBit(n, left);
        int rightBit = getBit(n, right);

        if (leftBit != rightBit) {
            n = flipBit(n, left);
            n = flipBit(n, right);
        }


        right--;
        left++;
    }

    cout << n;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}