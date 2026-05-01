#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    set<int> s1;
    set<int> s2;

    int sum = (n * (n + 1)) / 2;

    if (sum % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO";
        return;
    }

    int num = sum / 2;

    for (int i = n; i > 0; i--) {
        if (i <= num) {
            num -= i;

            s1.insert(i);
        } else {
            s2.insert(i);
        }
    }

    cout << s1.size() << endl;

    for (int x: s1) {
        cout << x << " ";
    }

    cout << endl;

    cout << s2.size() << endl;

    for (int x: s2) {
        cout << x << " ";
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