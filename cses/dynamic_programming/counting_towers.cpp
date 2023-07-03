#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define ld long double
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

ll dp[1000007][2];

ll solve(int n, int flag)
{
    if (n == 1)
        return 1 % M;
    if (dp[n][flag] != -1)
        return dp[n][flag];
    if (flag == 0)
    {
        return dp[n][flag] = (solve(n - 1, 1) % M + (4 % M * solve(n - 1, 0) % M) % M) % M;
    }
    if (flag == 1)
    {
        return dp[n][flag] = (2 * solve(n - 1, 1) % M + solve(n - 1, 0) % M) % M;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    rp(i, 0, 1000005) dp[i][0] = dp[i][1] = -1;

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        cout << (solve(n, 0) % M + solve(n, 1) % M) % M << "\n";
    }
    return 0;
}