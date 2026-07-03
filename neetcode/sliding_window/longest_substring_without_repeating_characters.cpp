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
    string s;

    cin >> s;

    unordered_set<char> st;

    int left = 0;
    int len = s.length();
    int max_val = 0;

    for (int right = 0; right < len; right++) {
        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        max_val = max(max_val, right - left + 1);
    }

    cout << max_val;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}