#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int partition(int arr[], int l, int r) {
    int mid = (l + r) / 2;

    int pivot = arr[mid];

    int i = l - 1;
    int j = r + 1;

    while(1) {
        do {
            ++i;
        } while (arr[i] < pivot && i <= r);
        
        do {
            --j;
        } while (arr[j] > pivot && j >= 0);

        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    return j;
}

void quicksort(int arr[], int l, int r) {
    if (l >= r) return;

    int p = partition(arr, l, r);

    quicksort(arr, l, p);

    quicksort(arr, p + 1, r);
}

void solve() {
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

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