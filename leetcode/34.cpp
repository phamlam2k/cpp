#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void search(vector<int> &arr, vector<int> &check, int target, int left, int right) {
    if (left > right) return;

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        if (check[0] == -1 || check[0] > mid) {
            check[0] = mid;
        }

        if (check[1] == -1 || check[1] < mid) {
            check[1] = mid;
        }

        search(arr, check, target, left, mid - 1);
        search(arr, check, target, mid + 1, right);
    }

    if (arr[mid] < target) {
        search(arr, check, target, mid + 1, right);
    } else {
        search(arr, check, target, left, mid - 1);
    }
}

void solve() {
    int n, target;

    cin >> n >> target;

    vector<int> check(2);
    vector<int> arr(n);

    check[0] = -1;
    check[1] = -1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    search(arr, check, target, 0, n - 1);

    cout << check[0] << " - " << check[1];
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}