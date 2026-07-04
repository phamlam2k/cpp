#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;
    
    cin >> n;

    vector<int> temperatures(n);

    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    vector<int> arr(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        if (st.empty()) {
            st.push(i);
            arr[i] = i;

            continue;
        }
        
        arr[i] = st.top();
        st.push(i);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        ans[i] = arr[i] - i;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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