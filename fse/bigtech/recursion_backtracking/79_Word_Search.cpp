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

bool dfs(vector<vector<char>> &board, int i, int j, int n, int m, string &words, int idx)
{
    if (idx >= words.size())
    {
        return true;
    }

    if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] != words[idx])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, i + 1, j, n, m, words, idx + 1) || dfs(board, i, j + 1, n, m, words, idx + 1) || dfs(board, i - 1, j, n, m, words, idx + 1) || dfs(board, i, j - 1, n, m, words, idx + 1);

    board[i][j] = temp;
    return found;
}

void solve()
{
    int n, m;
    string words;

    cin >> n >> m >> words;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(board, i, j, n, m, words, 0))
            {
                cout << true;

                return;
            }
        }
    }

    cout << false;
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