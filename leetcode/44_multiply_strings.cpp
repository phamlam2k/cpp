#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str1, str2;
    
    cin >> str1 >> str2;

    if (str1 == "0" || str2 == "0") {
        cout << "0";
        return;
    }

    int len1 = str1.length();
    int len2 = str2.length();

    int n = len1 + len2;

    vector<int> arr(n, 0);
    
    int i = len1 - 1;
    int idx = n - 1;

    while (i >= 0)
    {
        int j = len2 - 1;
        int idx2 = idx;

        int n1 = str1[i] - '0';
        
        while (j >= 0) {
            int n2 = str2[j] - '0';
    
            int mul = n1 * n2;
            
            int sum = mul + arr[idx2];

            if (sum >= 10) {
                int sum_p = sum % 10;
                int sum_r = sum / 10;

                arr[idx2] = sum_p;

                int s2 = arr[idx2 - 1] + sum_r;
                
                arr[idx2 - 1] = s2 % 10;

                if (s2 >= 10) {
                    arr[idx2 - 2] += s2 / 10;
                }
            } else {
                arr[idx2] = sum;
            }

            j--;
            idx2--;
        }

        i--;
        idx--;
    }
    
    string ans = "";

    for (int i = 0; i < n; i++) {
        if (ans.empty() && arr[i] == 0) continue;

        ans += to_string(arr[i]);
    }

    cout << ans;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve(); 
    }
}