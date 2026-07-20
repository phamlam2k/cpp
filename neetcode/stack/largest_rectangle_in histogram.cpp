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

    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> left(n);
    vector<int> right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = 0;
        } else {
            left[i] = st.top() + 1;
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n - 1;
        } else {
            right[i] = st.top() - 1;
        }
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int area = heights[i] * (right[i] - left[i] + 1);
        maxArea = max(maxArea, area);
    }

    cout << maxArea << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}