#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <math>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int c;

    cin >> c;

    int left = 0;
    int right = sqrt(c);

    while (left <= right) {
        int ans = left * left + right * right;

        if (ans == c) {
            cout << true;

            return;
        }

        if (ans > c) {
            right--;
        } else {
            left++;
        }
    }

    cout << false;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}