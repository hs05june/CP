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

bool do_dfs;
int parent[2007], visited[2007], cycle[2007];
deq graph[2007];

void dfs(int n, int par, int z)
{
    parent[n] = par;
    for (auto i : graph[n])
    {
        if (par == i)
            continue;
        if (i == z)
            do_dfs = true;
        if (visited[i] == 0)
        {
            visited[i] = 1;
            cycle[i] = 1 + cycle[n];
            dfs(i, n, z);
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
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        rp(i, 0, n + 1)
        {
            visited[i] = 0;
            parent[i] = 0;
            cycle[i] = 0;
            graph[i].clear();
        }

        rp(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        bool done = false;

        rp(i, 1, n + 1)
        {
            if (sz(graph[i]) >= 4)
            {
                rp(j, 0, n + 1)
                {
                    visited[j] = 0;
                    parent[j] = 0;
                    cycle[j] = 0;
                }

                do_dfs = false;

                visited[i] = 1;
                cycle[i] = 0;
                dfs(i, 0, i);
                if (!do_dfs)
                    continue;
                done = true;

                int x = LLONG_MAX, y = i;

                for (auto j : graph[i])
                {
                    if (cycle[j] >= 2 && cycle[j] < x)
                    {
                        y = j;
                        x = cycle[j];
                    }
                }

                rp(j, 0, n + 1) visited[j] = 0;

                x = i;
                visited[x] = visited[y] = 1;

                vector<pii> ans;
                ans.pb({x, y});
                x = y;

                while (x != i)
                {
                    for (auto j : graph[x])
                    {
                        if (cycle[j] == cycle[x] - 1)
                        {
                            y = j;
                            ans.pb({x, y});
                            x = j;
                            visited[x] = visited[y] = 1;
                            break;
                        }
                    }
                }

                int cnt = 0;

                for (auto j : graph[x])
                {
                    if (visited[j] == 0)
                    {
                        cnt++;
                        ans.pb({i, j});
                    }
                    if (cnt == 2)
                        break;
                }

                cout << "YES\n"
                     << sz(ans) << "\n";

                for (auto j : ans)
                {
                    cout << j.f << " " << j.s << "\n";
                }

                break;
            }
        }

        if (!done)
            cout << "NO\n";
    }

    return 0;
}