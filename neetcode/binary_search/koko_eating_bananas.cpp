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
    int n, h;

    cin >> n >> h;

    vector<int> piles(n);

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int res = right;

    while (left < right) {
        long long total_hour = 0;
        int k = left + (right - left) / 2;

        for (int pile: piles) {
            total_hour += (pile + k - 1) / 2;
        }

        if (total_hour <= h) {
            res = k;
            right = k - 1;
        } else {
            left = k + 1;
        }
    }

    cout << res;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}