#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

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

    int left = 0;
    int right = n - 1;
    int max_value = 0;

    while (left < right) {
        int minH = min(nums[left], nums[right]);
        int w = right - left;

        max_value = max(max_value, minH * w);

        if (nums[left] < nums[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_value;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}