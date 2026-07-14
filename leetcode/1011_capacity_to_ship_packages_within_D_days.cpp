#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int getDays(vector<int>& weights, int capacity) {
    int days = 1;
    int currentLoad = 0;

    for (int w : weights) {
        if (currentLoad + w > capacity) {
            days++;
            currentLoad = w;
        } else {
            currentLoad += w;
        }
    }
    return days;
}

void solve() {
    int n, days;

    cin >> n >> days;

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int maxVal = *max_element(weights.begin(), weights.end());
    int right = 0;

    for (int w: weights) {
        right += w;
    }

    int left = maxVal;
    int res = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int val = getDays(weights, mid);

        if (val <= days) {
            res = min(res, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}