/*
 * Problem: Pascal's Triangle
 * Link: https://leetcode.com/problems/pascals-triangle/
 * Idea:
 *  - I use Dynamic Programing for this solution because we can see the next step of result, that can be caculated by the previous step.
 *  - Example: 1 2 1 -> 1 3 3 1
 *      + 2 point start and end will be 1 but in the middle we have 1 + 2 = 3 and 2 + 1 = 3 too.
 * Big O:
 * - TC: O(n * i) = O(n^2)
 * - SC: O(n) + O(n * i) = O(n)
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
    int n;

    cin >> n;

    vector<vector<int>> results;
    
    for (int i = 0; i < n; i++) {
        // Init the array to save the results of each step
        vector<int> nums(i + 1, 1);

        for (int j = 1; j < i; j++) {
            // This is caculated by the prev result of the results list
            nums[j] = results[i - 1][j - 1] + results[i - 1][j];
        }

        results.push_back(nums);
    }

    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < results[i].size(); j++) {
            if (j) cout << ",";
            cout << results[i][j];
        }
        cout << "]\n";
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}