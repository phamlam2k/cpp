#include <bits/stdc++.h>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct Data
{
    int x;
    string str;
};


void merge(int arr[], int l, int m, int r) {
    vector<int> v1(arr + l, arr + m + 1);
    vector<int> v2(arr + m + 1, arr + r + 1);

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j]) {
            arr[l] = v1[i];
            i++;
        } else {
            arr[l] = v2[j];
            j++;
        }

        l++;
    }
    
    while(i < v1.size()) {
        arr[l] = v1[i];
        l++;
        i++;
    }

    while(j < v2.size()) {
        arr[l] = v2[j];
        l++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void solve() {
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
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