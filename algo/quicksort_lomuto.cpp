#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int parti(int arr[], int l, int r) {
    int i = l - 1;
    int pivot = arr[r];

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            ++i;

            swap(arr[i], arr[j]);
        }
    }

    ++i;

    swap(arr[i], arr[r]);

    return i;
}

void quicksort(int arr[], int l, int r) {
    if (l >= r) return;

    int p = parti(arr, l, r);

    quicksort(arr, l, p - 1);
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