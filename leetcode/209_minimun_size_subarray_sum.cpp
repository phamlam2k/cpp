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
    int n, target;

    cin >> n >> target;

    vector<int> nums(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0;
    int right = 0;
    int sum = nums[0];
    int min_len = INT_MAX;

    if (sum >= target) {
        cout << 1;

        return;
    }

    while (right < n && left < n) {
        if (nums[right] >= target || nums[left] >= target) {
            cout << 1;

            return;
        }
        
        if (sum >= target) {
            min_len = min(min_len, right - left + 1);

            sum -= nums[left];
            
            left++;
        }

        if (sum < target) {
            right++;

            if (right < n) {
                sum += nums[right];
            }
        }
    }

    if (min_len == INT_MAX) {
        cout << 0;
    } else {
        cout << min_len;
    }

    return;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}