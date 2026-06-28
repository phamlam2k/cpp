#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

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

    unordered_set<int> st(nums.begin(), nums.end());
    int longest_len = 0;

    for (const auto& x: st) {
        int count = 1;
        int init = x;

        while (st.count(init + 1))
        {
            count++;
            init++;
        }

        longest_len = max(longest_len, count);
    }

    cout << longest_len;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}