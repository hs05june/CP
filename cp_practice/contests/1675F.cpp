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

set<int> elements;
deq graph[200007];
pii levels[200007];
int visited[200007];
int visited2[200007];
int visited1[200007];

pii dfs(int n, int m)
{
    pii x = {0, 0};
    if (n == m)
        x.s = 1;
    if (elements.count(n))
        x.f = 1;
    for (auto i : graph[n])
    {
        if (visited[i] != 1)
        {
            visited[i] = 1;
            pii y = dfs(i, m);
            (x.f) |= (y.f);
            (x.s) |= (y.s);
        }
    }
    return levels[n] = x;
}

int dfs1(int n, int m)
{
    if (n == m)
        return 0;
    int ans = 0;
    for (auto i : graph[n])
    {
        if (visited1[i] == 0)
        {
            visited1[i] = 1;
            auto k = levels[i];
            if (k.f == 1 && k.s == 0)
            {
                ans += (2 + dfs1(i, m));
            }
            else if (k.s == 1)
            {
                ans += (1 + dfs1(i, m));
            }
        }
    }
    return ans;
}

int dfs2(int n)
{
    int ans = 0;
    for (auto i : graph[n])
    {
        if (visited1[i] == 0)
        {
            visited1[i] = 1;
            if (levels[i].f == 1)
            {
                ans += (2 + dfs2(i));
            }
        }
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
    cin >> t;

    while (t--)
    {

        elements.clear();
        int n, k;
        cin >> n >> k;
        rp(i, 0, n + 1)
        {
            levels[i].f = 0;
            levels[i].s = 0;
            graph[i].clear();
            visited1[i] = 0;
            visited[i] = 0;
            visited2[i] = 0;
        }
        int x, y;
        cin >> x >> y;

        rp(i, 0, k)
        {
            int z;
            cin >> z;
            elements.insert(z);
        }

        rp(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        visited[x] = 1;
        auto z = dfs(x, y);
        visited1[x] = 1;
        int ans = dfs1(x, y);
        ans += dfs2(y);

        cout << ans << "\n";
    }

    return 0;
}