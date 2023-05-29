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

int depth[200007], maxi[200007];
int n, ans, multiplier;
deq graph[200007];
int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans % mod;
}

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod) % mod;
}

void dfs(int n, int parent)
{
    maxi[n] = depth[n];
    for (auto i : graph[n])
    {
        if (i == parent)
            continue;
        depth[i] = 1 + depth[n];
        dfs(i, n);
        maxi[n] = max(maxi[n], maxi[i]);
    }
    ans = (ans % M + ((abs(maxi[n] - depth[n]) + 1) % M * multiplier % M) % M) % M;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while (t--)
    {

        ans = 0;
        cin >> n;

        rp(i, 0, n + 1)
        {
            depth[i] = 0;
            maxi[i] = 0;
            graph[i].clear();
        }

        rp(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        multiplier = power(2, (n - 1), M) % M;
        depth[1] = maxi[1] = 0;

        dfs(1, 0);

        cout << (ans % M) << "\n";
    }

    return 0;
}