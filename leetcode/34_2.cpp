#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int lowerBound(vector<int> &arr, int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    int idx = -1;
    int result = -1;

    if (arr[mid] == target) {
        idx = mid;
    }

    if (arr[mid] >= target) {
        result = lowerBound(arr, left, mid - 1, target);
    } else {
        result = lowerBound(arr, mid + 1, right, target);
    }

    if (result != -1) {
        idx = result;
    }

    return idx;
}

int upperBound(vector<int> &arr, int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    int idx = -1;
    int result = -1;
    
    if (arr[mid] == target) {
        idx = mid;
    }

    if (arr[mid] <= target) {
        result = upperBound(arr, mid + 1, right, target);
    } else {
        result = upperBound(arr, left, mid - 1, target);
    }

    if (result != -1) {
        idx = result;
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

    int n1 = lowerBound(arr, 0, n - 1, target);
    int n2 = upperBound(arr, 0, n - 1, target); 

    cout << n1 << " " << n2;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}