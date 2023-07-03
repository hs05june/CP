#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
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

int inv[200007], outv[200007];
deq graph[200007];
int dp[200007];

int dfs(int n)
{
    if (dp[n] != -1)
        return dp[n];
    int ans = 1;
    if (outv[n] >= 2)
    {
        for (auto i : graph[n])
        {
            if (inv[i] >= 2){
                ans = max(ans, 1 + dfs(i));}
        }
    }
    return dp[n] = ans;
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

        rp(i, 0, n + 1)
        {
            inv[i] = outv[i] = 0;
            dp[i] = -1;
        }

        rp(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            outv[a]++;
            inv[b]++;
        }

        int ans = 1;
        rp(i, 1, n + 1)
        {
            ans = max(ans, dfs(i));
        }

        cout << ans << "\n";
    }

    return 0;
}