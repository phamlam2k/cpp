#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <deque>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct CompareMinSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};

void solve() {
    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (mp[nums[i]]) {
            mp[nums[i]]++;
        } else {
            mp[nums[i]] = 1;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMinSecond> pq;

    for (const auto [key, value]: mp){
        pq.push({ key, value });

        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> ans;

    while (!pq.empty())
    {
        int val = pq.top().first;

        ans.push_back(val);

        pq.pop();
    }

    int len = ans.size();

    for (int i = 0; i < len; i++) {
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