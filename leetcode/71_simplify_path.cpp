#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string path;

    cin >> path;

    string token;
    vector<string> st;
    int len = path.length();
    int idx = 0;

    while (idx < len) {
        if (path[idx] == '/') {
            idx++;
            continue;
        }

        token = "";

        while(idx < len && path[idx] != '/') {
            token += path[idx];
            idx++;
        }

        if (token == ".") {

        } else if (token == "..") {
            if (!st.empty()) {
                st.pop_back();
            }
        } else {
            st.push_back(token);
        }
    }

    string ans = "";
    for (int i = 0; i < st.size(); i++) {
        ans += "/" + st[i];
    }

    if (ans == "") {
        ans = "/";
    }

    cout << ans;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}