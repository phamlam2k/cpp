#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }    

    int len = arr.size();

    int left = 1;
    int right = len;
    int ans = INT_MIN;

    while (left < right) {
        int res = (right - left) * min(arr[left], arr[right]);

        ans = max(ans, res);

        if (arr[left] > arr[right]) {
            right--;
        } else {
            left++;
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