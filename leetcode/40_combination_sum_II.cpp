#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void combinationSum (vector<int> &arr, vector<vector<int>> &ans, vector<int> &check, int n, int idx, int target) {
    if (target == 0) {

        ans.push_back(check);

        return;
    }

    if (target < 0) {
        return;
    }

    for (int i = idx; i < n; i++) {
        if (i > idx && arr[i] == arr[i - 1]) continue;

        check.push_back(arr[i]);

        combinationSum(arr, ans, check, n, i + 1, target - arr[i]);

        check.pop_back();
    }
}

void solve() {
    int n, target;

    cin >> n >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> check;

    combinationSum(arr, ans, check, n, 0, target);

    int s1 = ans.size();

    for (int i = 0; i < s1; i++) {
        int s = ans[i].size();

        for (int j = 0; j < s; j++) {
            cout << ans[i][j] << " ";
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
}