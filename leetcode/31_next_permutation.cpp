#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool nextPermutation(vector<int> &arr, int n) {
    if (n <= 1) return false;

    int left = n - 2;

    while (left >= 0 && arr[left] >= arr[left + 1]) {
        left--;
    }

    if (left < 0) return false;

    int right = n - 1;
    
    while (arr[left] >= arr[right]) {
        right--;
    }
    swap(arr[left], arr[right]);

    left++;
    right = n - 1;
    
    while (left < right) {
        swap(arr[left], arr[right]);
        left++; right--;
    }

    return true;
}

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (nextPermutation(arr, n)) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
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