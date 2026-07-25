/**
 * Problem: 27. Remove Element.
 * Link: https://leetcode.com/problems/remove-element
 * 
 * Description: 
 *   + We have the array of numbers, and variable named 'val', when you go through the array if the number is not equal to 'val', put it the next top elements. Otherwise put all the the last index in array.
 * 
 */
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
    int n, val;

    cin >> n >> val;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int slow = 0;

    for (int fast = 0; fast < n; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    cout << slow;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}