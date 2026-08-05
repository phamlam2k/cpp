#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// void solve() {
//     int n, m;

//     cin >> n >> m;

//     vector<int> nums1(n);
//     vector<int> nums2(m);

//     for (int i = 0; i < n; i++) {
//         cin >> nums1[i];
//     }

//     for (int i = 0; i < m; i++) {
//         cin >> nums2[i];
//     }

//     unordered_map<int, int> mp;
//     stack<int> stackMaxValue;

//     for (int i = m - 1; i >= 0; i--) {
//         while (!stackMaxValue.empty() && nums2[i] > stackMaxValue.top()) {
//             stackMaxValue.pop();
//         }

//         if (stackMaxValue.empty()) {
//             mp[nums2[i]] = -1;
//         } else {
//             mp[nums2[i]] = stackMaxValue.top();
//         }

//         stackMaxValue.push(nums2[i]);
//     }

//     vector<int> ans(n);

//     for (int i = 0; i < n; i++) {
//         ans[i] = mp[nums1[i]];
//     }

//     for (int i = 0; i < n; i++) {
//         cout << ans[i] << " ";
//     }
// }

void solve() {
    int n, m;

    cin >> n >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> ans;
    int j = 0;

    for (int i = 0; i < n; i++) {
        j = 0;

        while (nums1[i] != nums2[j]) j++;
        while (nums1[i] >= nums2[j]) j++;

        if (j >= m) { 
            ans.push_back(-1);
        } else {
            ans.push_back(nums2[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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