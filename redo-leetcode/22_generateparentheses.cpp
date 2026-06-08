#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void generateParent(string str, int n, int left, int right) {
    if (left == n && right == n) {
        cout << str << endl;
        
        return;
    }

    
    if (left < n) {
        generateParent(str + '(', n, left + 1, right);
    }

    if (left > right) {

        generateParent(str + ')', n, left, right + 1);
    }
}

void solve() {
    int n;

    cin >> n;

    string str = "";

    generateParent(str, n, 0, 0);
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}