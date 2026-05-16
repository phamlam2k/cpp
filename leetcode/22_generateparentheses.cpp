#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void backtracking(vector<string> *ans,string str, int openN, int closedN, int n) {
    if (openN == n && closedN == n) {
        ans->push_back(str);
        return;
    }


    if (openN < n) {
        backtracking(ans, str + '(', openN + 1, closedN, n);
    }

    if (closedN < openN) {
        backtracking(ans, str + ')', openN, closedN + 1, n);
    }
}

void solve() {
    int n;

    cin >> n;

    vector<string> ans;

    backtracking(&ans, "", 0, 0, n);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
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