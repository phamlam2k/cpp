#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, target;

    cin >> n >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        for (int j = n - 1; j > i + 2; j--) {
            if (j < n - 1 && arr[j] == arr[j + 1]) {
                continue;
            }

            int r2 = j - 1;
            int l = i + 1;

            while (l < r2) {
                int sum = 0LL + arr[i] + arr[l] + arr[r2] + arr[j];

                if (sum == target) {
                    ans.push_back({ arr[i], arr[l], arr[r2], arr[j] });
                    r2--;
                    l++;

                    while (l < r2 && arr[l] == arr[l - 1]) {
                        l++;
                    }
                    
                    while (l < r2 && arr[r2] == arr[r2 + 1]) {
                        r2--;
                    }
                } else if (sum > target) {
                    r2--;
                } else {
                    l++;
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
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