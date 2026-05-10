#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n);
    vector<vector<int>> ans;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int len = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < len - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[right] + arr[left];

            if (sum == 0) {
                vector<int> ss = { arr[i], arr[left], arr[right] };
                ans.push_back(ss);

                while (left < right && arr[left] == arr[left + 1]) {
                    left++;
                }
                
                left++;
                right--;
                continue;
            }

            if (sum < 0) {
                left++;
            }

            if (sum > 0) {
                right--;
            }
        }
    }

    int lent = ans.size();

    for (int i = 0; i < lent; i++) {
        for (int j = 0; j < 3; j++) {
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