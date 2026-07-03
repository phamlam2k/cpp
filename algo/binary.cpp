#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n, 0);

    int i = n - 1;

    while (i >= 0)
    {   
        for (int x: arr) {
            cout << x;
        }

        i = n - 1;

        while(arr[i] == 1 && i >= 0) {
            arr[i] = 0;
            i--;
        }

        arr[i] = 1;

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