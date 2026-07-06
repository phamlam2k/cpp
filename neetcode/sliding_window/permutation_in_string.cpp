#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string s1, s2;

    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 > len2) {
        cout << false;

        return;
    }

    vector<int> arr1(26, 0);
    vector<int> arr2(26, 0);
    
    for (int i = 0; i < len1; i++) {
        arr1[s1[i] - 'a']++;
        arr2[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (arr1[i] == arr2[i]) {
            matches++;
        }
    }

    int left = 0;

    for (int i = len1; i < len2; i++) {
        if (matches == 26) {
            cout << true;

            return;
        }
        
        // right
        int idx1 = s2[i] - 'a';
        arr2[idx1]++;

        if (arr1[idx1] == arr2[idx1]) {
            matches++;
        } else if (arr1[idx1] + 1 == arr2[idx1]) {
            matches--;
        }

        // left
        int idx2 = s2[left] - 'a';
        arr2[idx2]--;

        if (arr1[idx2] == arr2[idx2]) {
            matches++;
        } else if (arr1[idx2] - 1 == arr2[idx2]) {
            matches--;
        }

        left++;
    }

    bool check = matches == 26;

    cout << check;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}