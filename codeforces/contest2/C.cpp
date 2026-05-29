#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;
    
    cin >> n;

    int len = 3 * n;

    vector<int> arr(n);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int idx = 0;

    for (int i = n + 1; i < len; i +=2) {
        ans.push_back(arr[idx]);
        ans.push_back(i);
        ans.push_back(i + 1);

        idx += 1;
    }

    int ans_len = ans.size();

    for (int i = 0; i < ans_len; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}