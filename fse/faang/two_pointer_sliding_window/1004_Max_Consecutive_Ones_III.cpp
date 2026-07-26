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
    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int slow = 0;
    int checked = 0;
    int fast = 0;
    int max_range = 0;

    while (fast < n) {
        if (checked > k) {
            if (nums[slow] == 0) {
                checked--;
            }

            slow++;

            continue;
        }

        if (nums[fast] == 0) {
            checked++;   
        }

        if (checked <= k) {
            max_range = max(max_range, fast - slow + 1);
        } 

        fast++;
    }


    cout << max_range;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}