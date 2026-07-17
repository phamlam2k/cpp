#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*') {
        return true;
    }

    return false;
}

void solve() {
    string str;

    cin >> str;

    stack<string> st;
    int len = str.size();

    for (int i = 0; i < len; i++) {
        if (isOperator(str[i])) {
            string opt1 = st.top(); st.pop();
            string opt2 = st.top(); st.pop(); 

            string pre = str[i] + opt2 + opt1;
            
            st.push(pre);
        } else {
            st.push(string(1, str[i]));
        }
    }

    cout << st.top();

    st.pop();
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}