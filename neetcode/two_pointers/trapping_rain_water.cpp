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

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int leftMax = 0;
    vector<int> leftArr(n);

    for (int i = 0; i < n; i++) {
        leftArr[i] = leftMax; 

        if (height[i] > height[leftMax]) {
            leftMax = i;
        }
    }

    int rightMax = n - 1;
    vector<int> rightArr(n);

    for (int i = n - 1; i >= 0; i--) {
        rightArr[i] = rightMax; 

        if (height[i] > height[rightMax]) {
            rightMax = i;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cout << leftArr[i] << " " << rightArr[i] << endl;
        int minH = min(height[leftArr[i]], height[rightArr[i]]);

        if (minH - height[i] > 0) {
            ans += minH - height[i];
        }
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