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

    vector<int> ansLeft(n);
    vector<int> ansRight(n);

    for (int i = 0; i < n; i++) {
        while (!heights.empty() && skylines[i] > heights.top()) {
            heights.pop();
        }

        if (heights.empty()) {
            ansRight[i] = -1;
        } else {
            ansRight[i] = heights.top();
        }

        heights.push(skylines[i]);
    }

    while (!heights.empty()) {
        heights.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!heights.empty() && skylines[i] > heights.top()) {
            heights.pop();
        }

        if (heights.empty()) {
            ansLeft[i] = -1;
        } else {
            ansLeft[i] = heights.top();
        }

        heights.push(skylines[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << max(ansLeft[i], ansRight[i]) << " ";  
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