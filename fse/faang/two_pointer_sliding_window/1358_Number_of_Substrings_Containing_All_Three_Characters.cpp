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

    cin >> s;

    int len = s.length();

    int count[3] = { 0, 0, 0 };
    int left = 0;
    int total = 0;

    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;

        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            count[s[left] - 'a']--;
            total += len - i;

            left++;
        }
    }

    cout << total;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}