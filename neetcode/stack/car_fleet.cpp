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
    int target, n;

    cin >> n >> target;

    vector<int> position(n);
    vector<int> speed(n);

    vector<pair<int, int>> res(n);

    for (int i = 0; i < n; i++) {
        cin >> position[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    for (int i = 0; i < n; i++) {
        res.push_back({ position[i], speed[i] });
    }

    sort(res.rbegin(), res.rend());

    stack<double> st;

    for (int i = 0; i < n; i++) {
        double num = (double)(target - res[i].first) / res[i].second;

        if (st.empty()) {
            st.push(num);

            continue;
        }

        double t = st.top();

        if (t < num) {
            st.push(num);
        }
    }

    cout << st.size();
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}