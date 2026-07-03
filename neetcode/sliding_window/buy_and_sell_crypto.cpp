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

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int minVal = nums[0];

    vector<int> arr(n);

    arr[0] = -1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > minVal) {
            arr[i] = nums[i] - minVal;
        } else {
            arr[i] = -1;
        }

        minVal = min(minVal, nums[i]);
    }

    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        maxVal = max(maxVal, arr[i]);
    }

    if (maxVal == -1) {
        cout << 0 << endl;
        return;
    }

    cout << maxVal << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}