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

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int total = nums[i] + nums[left] + nums[right];
            
            if (total < 0) {
                left++;
            } else if (total > 0) {
                right--;
            } else {
                ans.push_back({ nums[i], nums[left], nums[right] });
                left++;
                right--;

                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                
                while (left < right && nums[right] == nums[right + 1])
                {
                    right--;
                }   
            }
        }
    }

    for (vector<int> x: ans) {
        for (int a: x) {
            cout << a << " ";
        }

        cout << endl;
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