#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void backTracking(vector<int> &arr, vector<vector<int>> &ans, vector<bool> used, vector<int> &choose, int n) {
    if (choose.size() == n) {
        ans.push_back(choose);

        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;
        
        choose.push_back(arr[i]);
        used[i] = true;

        backTracking(arr, ans, used, choose, n);

        choose.pop_back();
        used[i] = false;
    }

}

void solve() {
    int n;

    cin >> n; 

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans;
    vector<int> choose;
    vector<bool> used(n, false);

    sort(arr.begin(), arr.end());

    backTracking(arr, ans, used, choose, n);

    for (const auto& row : ans) {
        for (int element : row) {
            cout << element << " ";
        }

        cout << endl;
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}