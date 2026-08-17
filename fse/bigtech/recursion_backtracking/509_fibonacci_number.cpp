#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

unordered_map<int, int> memo;

// Đối với những bài toán đệ quy, space cần cho recursion được tính qua công thức
// Độ cao của cây đệ quy x số lượng local variable trong hàm đệ quy
// n x O(1) = O(n)

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (memo[n])
    {
        return memo[n];
    }

    int fi = fibo(n - 1) + fibo(n - 2);
    memo.insert({n, fi});

    return fi;
}

void solve()
{
    int n;

    cin >> n;

    int res = fibo(n);

    cout << res;
}

signed main()
{
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}