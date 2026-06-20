#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include<stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;
    string str;

    cin >> n;
    cin >> str;

    stack<char> st;
    
    int len = str.length();

    st.push(str[0]);

    int res = 0;

    for (int i = 1; i < len; i++) {
        if (st.empty()) {
            st.push(str[i]);

            continue;
        }

        char start = st.top();

        if (start == str[i]) continue;

        st.pop();

        if (str[i] == 'S') {
            res--;
        } else {
            res++;
        }

        st.push(str[i]);
    }

    if (res <= 0) {
        cout << "NO";
    } else {
        cout << "YES";
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