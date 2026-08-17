#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <deque>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, limit;

    cin >> n >> limit;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0;

    int res = 1;

    deque<int> maxQueue;
    deque<int> minQueue;

    for (int right = 0; right < n; right++) {
        while (!maxQueue.empty() && nums[right] > maxQueue.back()) {
            maxQueue.pop_back();
        }

        while (!minQueue.empty() && nums[right] < minQueue.back()) {
            minQueue.pop_back();
        }

        maxQueue.push_back(nums[right]);
        minQueue.push_back(nums[right]);

        while (!maxQueue.empty() && !minQueue.empty() && maxQueue.front() - minQueue.front() > limit) {
            if (nums[left] == maxQueue.front()) {
                maxQueue.pop_front();
            }
            if (nums[left] == minQueue.front()) {
                minQueue.pop_front();
            }
            left++;
        }

        res = max(res, right - left + 1);
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