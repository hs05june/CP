/*130. Surrounded Regions
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

bool visited[207][207];
int arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y, int n, int m, vector<vector<char>> &board)
{
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + arr[i][0], y1 = y + arr[i][1];
        if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && board[x1][y1] == 'O' && !visited[x1][y1])
        {
            visited[x1][y1] = true;
            dfs(x1, y1, n, m, board);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board;

    rp(i,0,n){
        vector<char> test;
        rp(j,0,m){
            char x;
            cin >> x;
            test.pb(x);
        }
        board.pb(test);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O' && !visited[i][0])
        {
            visited[i][0] = true;
            dfs(i, 0, n, m, board);
        }
        if (board[i][m - 1] == 'O' && !visited[i][m - 1])
        {
            visited[i][m - 1] = true;
            dfs(i, m - 1, n, m, board);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (board[n - 1][i] == 'O' && !visited[n - 1][i])
        {
            visited[n - 1][i] = true;
            dfs(n - 1, i, n, m, board);
        }
        if (board[0][i] == 'O' && !visited[0][i])
        {
            visited[0][i] = true;
            dfs(0, i, n, m, board);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
        }
    }

    rp(i, 0, n)
    {
        rp(j, 0, m)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}