#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string s;
    int k;

    cin >> s >> k;

    int left = 0;
    int right = 0;
    int len = s.length();
    int maxf = 0;
    int res = 0;
    unordered_map<char, int> mp;

    while (right < len) {
        mp[s[right]]++;

        maxf = max(maxf, mp[s[right]]);

        while ((right - left + 1) - maxf > k && left < right)
        {
            mp[s[left]]--;
            left++;
        }

        res = max(res, right - left + 1);
        right++;
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