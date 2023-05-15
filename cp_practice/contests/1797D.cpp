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

deq graph[300007];
int imp[300007], parent[300007], visited[300007], Size[300007];
set<pii> largest[300007];

void dfs(int n, int par)
{
    parent[n] = par;
    Size[n] = 1;
    for (auto i : graph[n])
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i, n);
        }
        if (i != par)
        {
            imp[n] += imp[i];
            Size[n] += Size[i];
            largest[n].insert({Size[i], -i});
        }
    }
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

        int n, m;
        cin >> n >> m;

        rp(i, 1, n + 1) cin >> imp[i];

        rp(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        visited[1] = 1;
        parent[1] = 0;

        dfs(1, 0);

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (a == 1)
            {
                cout << imp[b] << '\n';
            }
            else if (a == 2)
            {
                if (largest[b].empty())
                    continue;
                auto c = *(--largest[b].end());
                int x = c.f, y = -c.s;
                largest[parent[b]].erase({Size[b], -b});
                largest[b].erase(c);
                parent[y] = parent[b];
                parent[b] = y;
                imp[b] -= imp[y];
                imp[y] += imp[b];
                Size[b] -= Size[y];
                Size[y] += Size[b];
                largest[parent[y]].insert({Size[y], -y});
                largest[y].insert({Size[b], -b});
            }
        }
    }

    return 0;
}
