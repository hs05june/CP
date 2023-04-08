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

int dp[100007], parent[100007], height[100007];
deq graph[100007];

int dfs(int n)
{
    int ans = 1;
    for (auto i : graph[n])
    {
        ans = max(ans, 1 + dfs(i));
    }
    return height[n] = ans;
}

int solve(int n)
{

    if (dp[n] != -1)
        return dp[n];
    int ans = 0, maxi = 0;
    bool leaf = false;
    for (auto i : graph[n])
    {
        int z = solve(i);
        ans += z;
    }
    return dp[n] = max(ans, height[n]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while (t--)
    {

        int n;
        cin >> n;

        rp(i, 0, n + 1)
        {
            dp[i] = -1;
        }

        rp(i, 2, n + 1)
        {
            cin >> parent[i];
            graph[parent[i]].pb(i);
        }

        if (n == 1)
        {
            cout << "1\n";
            continue;
        }

        dfs(1);
        solve(1);

        cout << dp[1] << "\n";
    }

    return 0;
}