#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> deck(n);

    for (int i = 0; i < n; i++) {
        cin >> deck[i];
    }

    sort(deck.begin(), deck.end());

    queue<int> q;

    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    vector<int> ans(n);

    int i = 0;

    while(!q.empty() && i < n) {
        int first = q.front(); q.pop();
        if (!q.empty()) {
            int second = q.front(); q.pop();
    
            q.push(second);
        }
        ans[first] = deck[i];

        i++;
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