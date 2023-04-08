/*
85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
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

int histogram[207][207];

int solve(int x, int n, int m)
{
    int next_smaller[m + 1], prev_smaller[m + 1];
    for (int i = 1; i <= m; i++)
    {
        next_smaller[i] = m + 1;
        prev_smaller[i] = 0;
    }
    stack<pair<int, int>> st;
    for (int i = 1; i <= (m); i++)
    {
        if (st.empty())
        {
            st.push(make_pair(histogram[x][i], i));
        }
        else
        {
            while (!st.empty() && histogram[x][i] < st.top().first)
            {
                next_smaller[st.top().second] = i;
                st.pop();
            }
            st.push(make_pair(histogram[x][i], i));
        }
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = m; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push({histogram[x][i], i});
        }
        else
        {
            while (!st.empty() && histogram[x][i] < st.top().first)
            {
                prev_smaller[st.top().second] = i;
                st.pop();
            }
            st.push({histogram[x][i], i});
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= m; i++)
    {
        int left = prev_smaller[i], right = next_smaller[i];
        ans = max(ans, (right - left - 1) * histogram[x][i]);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<vector<char>> matrix;

        rp(i, 0, n)
        {
            vector<char> df;
            rp(j, 0, m)
            {
                char x;
                cin >> x;
                df.pb(x);
            }
            matrix.pb(df);
        }

        for (int i = 0; i <= m + 1; i++)
        {
            histogram[0][i] = -1;
            histogram[n + 1][i] = -1;
        }
        for (int i = 0; i <= n + 1; i++)
        {
            histogram[i][0] = -1;
            histogram[i][m + 1] = -1;
        }

        for (int i = 1; i <= m; i++)
        {
            histogram[1][i] = (matrix[0][i - 1] == '1');
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '0')
                {
                    histogram[i][j] = 0;
                }
                else
                {
                    histogram[i][j] = 1 + histogram[i - 1][j];
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, solve(i, n, m));
        }
        cout << ans << "\n";
    }

    return 0;
}