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

    vector<int> arr(n, 1);

    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] * nums[i - 1];
    }

    vector<int> res(n, 1);
    int point = 1;

    for (int i = n - 1; i >= 0; i--) {
        res[i] = arr[i] * point;
        point *= nums[i];
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}