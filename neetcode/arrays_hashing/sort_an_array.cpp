#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void merge (vector<int> &arr, int l, int mid, int r) {
    vector<int> v1(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> v2(arr.begin() + mid + 1, arr.begin() + r + 1);

    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0;
    int j = 0;

    while (i <= len1 - 1 && j <= len2 - 1) {
        if (v1[i] < v2[j]) {
            arr[l] = v1[i];
            i++;
        } else {
            arr[l] = v2[j];
            j++;
        }

        l++;
    }

    while (i <= len1 - 1) {
        arr[l] = v1[i];
        l++;
        i++;
    }

    while (j <= len2 - 1) {
        arr[l] = v2[j];
        l++;
        j++;
    }
}

void mergeSort (vector<int> &arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void solve() {
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}