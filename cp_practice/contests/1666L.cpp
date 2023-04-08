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

int start, ans;
deq graph[200007];
pii visited1[200007];
int parent[200007];
int parents[2];

void dfs(int n, int index)
{
    if (ans != 0)
        return;
    for (auto i : graph[n])
    {
        if (i == start)
        {
            continue;
        }
        if (visited1[i].f == 1 && visited1[i].s != index)
        {
            ans = i;
            parents[0] = parent[i];
            parents[1] = n;
            return;
        }
        else if (visited1[i].f == 0)
        {
            visited1[i] = {1, index};
            parent[i] = n;
            dfs(i, index);
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
        cin >> n >> m >> start;

        rp(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
        }

        for (int i = 0; i < sz(graph[start]); i++)
        {
            if (visited1[graph[start][i]].f == 1 && i != visited1[graph[start][i]].s)
            {
                parents[0] = parent[graph[start][i]];
                parents[1] = start;
                ans = graph[start][i];
                break;
            }
            visited1[graph[start][i]] = {1, i};
            parent[graph[start][i]] = start;
            dfs(graph[start][i], i);
        }

        if (ans == 0)
        {
            cout << "Impossible\n";
            continue;
        }

        cout << "Possible\n";

        deq path[2];

        rp(i, 0, 2)
        {
            path[i].pb(ans);
            int x = parents[i];
            while (x != start)
            {
                path[i].pb(x);
                x = parent[x];
            }
            path[i].pb(start);
            reverse(all(path[i]));
        }

        cout << sz(path[0]) << "\n";
        for (auto i : path[0])
        {
            cout << i << " ";
        }
        cout << "\n";

        cout << sz(path[1]) << "\n";
        for (auto i : path[1])
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}