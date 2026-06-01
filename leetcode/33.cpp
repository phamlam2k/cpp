#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int searchRotatedSortedArray(vector<int> &arr, int left, int right, int target) {
    if (left > right) return -1;

    int res = -1;
    int idx = -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[left] <= arr[mid]) {
        if (target >= arr[left] && target < arr[mid]) {
            res = searchRotatedSortedArray(arr, left, mid - 1, target);
        } else {
            res = searchRotatedSortedArray(arr, mid + 1, right, target);
        }
    } else {
        if (target > arr[mid] && target <= arr[right]) {
            res = searchRotatedSortedArray(arr, mid + 1, right, target);
        } else {
            res = searchRotatedSortedArray(arr, left, mid - 1, target);
        }
    }

    if (res != -1) {
        idx = res;
    }

    return idx;
}

void solve() {
    int n, target;

    cin >> n >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = searchRotatedSortedArray(arr, 0, n - 1, target);

    cout << result;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}