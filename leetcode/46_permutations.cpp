#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void reverseArr(vector<int> &arr, int left, int right) {
    while(left < right) {
        swap(arr[left], arr[right]);

        left++;
        right--;
    }
}

void solve() {
    int n;

    cin >> n; 

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int right = n - 1;

    while (right) {
        int left = right - 1;
        int num = arr[right];

        while (num < arr[left - 1] && left > 0) left--;

        if (left < 0) {
            right--;
            continue;
        }

        if (num > arr[left]) {
            swap(arr[left], arr[right]);
        }

        reverseArr(arr, left + 1, n - 1);

        right = n - 1;

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

    return 0;
}