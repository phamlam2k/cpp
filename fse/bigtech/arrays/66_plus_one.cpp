/**
 * Problem: 66. Plus One
 * Link: https://leetcode.com/problems/plus-one
 * 
 * - Description:
 *   + We have an array [1,2,3], the output will be [1,2,4] but if the array is [9] -> [1, 0] or [8,9,9] -> [9,0,0]. Easy to see that when you start from the right, 
 *     if the number is lower than 9, it just sum it to 1 and stop, but if the number is equal to 9, it will change to 0 and continue to the left until the number is lower than 9 or the index not lower than 0.
 * - Solution:
 *   + I will start from the right of the array, if the number is lower than 9, sum it to 1 and stop the loop.
 *   + And if the numer is equal to 9 -> change it to 0 and continue to loop.
 *   + When the loop is finish, under the loop we have to add 1 to the first index of the array. => O(n)
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

    vector<int> digits(n);

    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;

            return;
        }
    }

    vector<int> results(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        results[i] = digits[i - 1];
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