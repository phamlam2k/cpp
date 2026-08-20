#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<int>> Matrix;

Matrix mathMul(Matrix A, Matrix B)
{
    Matrix C(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

Matrix mulExp(Matrix base, int exp)
{
    Matrix res = {{1, 0}, {0, 1}};

    while (exp > 0)
    {
        if (exp & 1)
        {

            res = mathMul(res, base);
        }

        base = mathMul(base, base);

        exp >>= 1;
    }

    return res;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    Matrix T = {{1, 1}, {1, 0}};

    Matrix res = mulExp(T, n - 1);

    return res[0][0];
}

void solve()
{
    int n;

    cin >> n;

    cout << fibonacci(n);
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