#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, k;

    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int closet = INT_MAX;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (abs(k - sum) < closet) {
                ans = sum;
                closet = abs(k - sum);
            } 

            if (k - sum == 0) {
                cout << k;
                return;
            }
            
            if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << ans;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}