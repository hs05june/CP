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

int depth[200007], dparent[200007], parent[200007][20], euler[600007], first[200007], sparse[600007][25];
deq graph[200007];
int tim;

void dfs(int n, int par)
{
    first[n] = tim;
    euler[tim] = n;
    ++tim;
    for (auto i : graph[n])
    {
        if (i == par)
            continue;
        depth[i] = 1 + depth[n];
        parent[i][0] = n;
        dfs(i, n);
    }
    if (n != 1)
    {
        euler[tim] = parent[n][0];
        ++tim;
    }
}

void binary_jumping(int d, int n)
{
    for (int i = 1; (1 << i) <= d; i++)
    {
        rp(j, 1, n + 1)
        {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    rp(i, 1, n + 1)
    {
        int j = 0;
        dparent[i] = i;
        while (((1 << j)) <= d)
        {
            if (((1 << j) & d) != 0)
                dparent[i] = parent[dparent[i]][j];
            ++j;
        }
    }
}

void fill_sparse(int n)
{
    int maxi = 2 * n;
    rp(i, 1, maxi + 1)
    {
        sparse[i][0] = depth[euler[i]];
    }

    for (int j = 1; (1 << j) <= maxi; j++)
    {
        rp(i, 1, maxi + 1)
        {
            int k = j - 1;
            if (i + (1 << k) <= maxi + 10)
                sparse[i][j] = min(sparse[i][k], sparse[i + ((1LL) << k)][k]);
            else
                break;
        }
    }
}

int distance(int x, int y)
{
    if (first[x] > first[y])
        swap(x, y);
    int siz = first[y] - first[x] + 1;
    int ans = INT_MAX;
    int anc = first[x];
    int i = 0;
    while (siz >= (1 << i))
    {
        if ((siz & (1 << i)) != 0)
        {
            ans = min(ans, sparse[anc][i]);
            anc += ((1 << i));
        }
        ++i;
    }
    return (depth[x] + depth[y] - 2 * ans);
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

        int n, d;
        cin >> n >> d;

        rp(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        depth[1] = 0;
        parent[1][0] = 1;
        dfs(1, 1);

        binary_jumping(d, n);
        fill_sparse(n);

        set<int> to_visit[2];

        rp(i, 0, 2)
        {
            int m;
            cin >> m;
            rp(j, 0, m)
            {
                int x;
                cin >> x;
                to_visit[i].insert(x);
            }
        }

        rp(i, 0, 2)
        {
            for (auto j : to_visit[i])
            {
                int x = dparent[j];
                to_visit[(i + 1) % 2].insert(x);
            }
        }

        int ans = 0;

        rp(i, 0, 2)
        {
            int x = 1;
            rp(j, 0, 2 * n - 1)
            {
                if (to_visit[i].count(euler[j]))
                {
                    to_visit[i].erase(euler[j]);
                    ans += (distance(x, euler[j]));
                    x = euler[j];
                }
            }
            ans += distance(x, 1);
        }

        cout << ans << '\n';
    }

    return 0;
}