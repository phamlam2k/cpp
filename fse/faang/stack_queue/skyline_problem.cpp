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
    int n;

    cin >> n;

    vector<int> skylines(n);

    for (int i = 0; i < n; i++) {
        cin >> skylines[i];
    }

    stack<int> heights;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (!heights.empty() && skylines[i] > skylines[heights.top()]) {
            heights.pop();
        }

        if (heights.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = heights.top();
        }

        heights.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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