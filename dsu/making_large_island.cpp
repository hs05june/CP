/*
827. Making A Large Island
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
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

pair<int, int> parent[507][507];
int Rank[507][507];

pair<int, int> Find(int x, int y)
{
    if (parent[x][y] == make_pair(x, y))
        return make_pair(x, y);
    return parent[x][y] = Find(parent[x][y].first, parent[x][y].second);
}

void Union(pair<int, int> x, pair<int, int> y)
{
    pair<int, int> b = Find(x.first, x.second), a = Find(y.first, y.second);
    if (Rank[a.first][a.second] > Rank[b.first][b.second])
        swap(a, b);
    parent[a.first][a.second] = make_pair(b.first, b.second);
    if (Rank[a.first][a.second] == Rank[b.first][b.second])
        Rank[b.first][b.second]++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;

    int grid[n][m];

    rp(i, 0, n)
    {
        rp(j, 0, m)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            parent[i][j] = {i, j};
        }
    }
    int ans = 0;

    int arr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + arr[k][0], y = j + arr[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && Find(i, j) != Find(x, y))
                    {
                        Union(make_pair(i, j), make_pair(x, y));
                        // break;
                    }
                }
            }
        }
    }

    map<pair<int, int>, int> levels;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                auto z = Find(i, j);
                levels[z]++;
            }
        }
    }
    for (auto i : levels)
    {
        // cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
        ans = max(ans, i.second);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                set<pair<int, int>> uniq_parent;
                int check = 1;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + arr[k][0], y = j + arr[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                    {
                        auto z = Find(x, y);
                        uniq_parent.insert({z.first, z.second});
                    }
                }
                for (auto k : uniq_parent)
                {
                    check += levels[k];
                }
                ans = max(ans, check);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}