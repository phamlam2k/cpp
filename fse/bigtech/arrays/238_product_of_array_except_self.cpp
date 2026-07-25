/**
 * Problem: 238. Product of Array Except Self
 * Link: https://leetcode.com/problems/product-of-array-except-self
 * 
 * Descrition: 
 *  + We have an array that have random numbers, then we loop through the array.
 *  + When the loop stop in some index, we will multiply all the numbers in this array excepted the number in that index.
 * 
 * Solution: 
 *  + We can create 2 vector array, first one run from left to right, and second one run from right to left. 
 *  + Example: 
 *    1 2 3 4 -> (do the pre sum skill but here it is multiply) 1 2 6 24
 *    1 2 3 4 -> (do the pre sum skill but here it is multiply) 24 24 12 4 
 * 
 *  + If it in second index (the number is 3), so the multiply will be get the pre multiply in first index of array 1, and third index in array 2.
 *  + Example: 
 *    1 2 3 4
 *        |
 *      second index  
 *  
 *    1 2 6 24
 *      |
 *     pre multply in array 1
 *    24 24 12 4
 *             |   
 *          pre multply in array 2
 * 
 *    => result = 2 * 4 = 8;
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

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> left(n + 1, 1);
    vector<int> right(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i];
    }

    vector<int> results;

    for (int i = 1; i <= n; i++) {
        results.push_back(left[i - 1] * right[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << results[i] << " ";
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