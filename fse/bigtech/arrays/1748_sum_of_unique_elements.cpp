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

    sort(nums.begin(), nums.end());

    int sum = 0;
    int left = 0;
    int right = left + 1;

    while (right < n) {
        if (nums[left] != nums[right]) {
            sum += nums[left];
            left++;
            right++;

            continue;
        }

        while (nums[left] == nums[right]) {
            right++;
        }

        left = right;
        right++;
    }

    if (left == n - 1) {
        sum += nums[left];
    }

    cout << sum;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}