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
    string s;
    cin >> s;

    string res;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        int val = s[i] - '0';

        bool checkNumber = val >= 0 && val <= 9;
        bool checkUpper = val >= 17 && val <= 42;
        bool checkLower = val >= 49  && val <= 74;

        if (checkUpper) {
            res.push_back(s[i] + 32);
            continue;
        }

        if (checkNumber || checkLower) {
            res.push_back(s[i]);
        }
    }
    
    int left = 0;
    int right = res.length() - 1;

    while (left < right) {
        if (res[left] != res[right]) {
            cout << false;

            return;
        }

        left++;
        right--;
    }

    cout << true;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}