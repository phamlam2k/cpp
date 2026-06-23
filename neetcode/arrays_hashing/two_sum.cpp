#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, target;

    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> nums_set;

    for (int i = 0; i < n; i++) {
        if (nums[i] > target) continue;

        auto it = nums_set.find(nums[i]);
        
        if (it != nums_set.end()) {
            cout << nums_set[nums[i]] << " " << i;

            return;
        } else {
            int left = target - nums[i];
            nums_set.insert({ left, i });
        }
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