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
const ll M = 998244353;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;

    int dp[2][n + 1];
    memset(dp, 0, sizeof dp);
    deq ans(n + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= 650; i++)
    {
        memset(dp[i & 1], 0, sizeof dp[i & 1]);
        int curJump = k + i - 1;
        for (int x = 0; x <= n; x++)
        {

            int &ret = dp[i & 1][x];
            if (x - curJump >= 0)
            {
                ret = dp[(i - 1) & 1][x - curJump] + dp[i & 1][x - curJump];
                ret %= M;
            }
            (ans[x] += ret) %= M;
        }
        ++curJump;
    }

    for (int x = 1; x <= n; x++)
        cout << ans[x] << " ";
    return 0;
}