#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string binarySearch(vector<int> &arr, int left, int right, int target) {
    int mid = (left + right) / 2;

    if (left > right) return "Not found";

    if (arr[mid] == target) return "Found";

    if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, right, target);
    } else {
        return binarySearch(arr, left, mid - 1, target);
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

    string ans = binarySearch(arr, 0, n - 1, target);

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