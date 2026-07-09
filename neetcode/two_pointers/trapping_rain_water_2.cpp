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
    int n;

    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int l = 0; int r = n - 1;
    int leftMax = heights[l];
    int rightMax = heights[r];
    int res = 0;

    while (l < r) {
        if (heights[l] < heights[r]) {
            l++;
            leftMax = max(leftMax, heights[l]);
            res += leftMax - heights[l];
        } else {
            r--;
            rightMax = max(rightMax, heights[r]);
            res += rightMax - heights[r];
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