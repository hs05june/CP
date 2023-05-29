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

int parent[200007], Size[200007];

int find_parent(int n)
{
    if (n == parent[n])
        return n;
    return parent[n] = find_parent(parent[n]);
}

void Union(int a, int b)
{
    int x = find_parent(a), y = find_parent(b);
    if (x == y)
        return;
    if (Size[x] > Size[y])
        swap(x, y);
    parent[x] = y;
    Size[y] += Size[x];
}

set<int> graph[200007];
int visited[200007];
int ans;

void dfs(int n, int par, int x)
{
    for (auto i : graph[n])
    {
        if (i == par)
            continue;
        if (visited[i] == x)
        {
            ans++;
            continue;
        }
        if (visited[i] == 0)
        {
            visited[i] = x;
            dfs(i, n, x);
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

        int n;
        cin >> n;

        ans = 0;
        rp(i, 1, n + 1)
        {
            parent[i] = i;
            Size[i] = 1;
            visited[i] = 0;
            graph[i].clear();
        }

        rp(i, 1, n + 1)
        {
            int x;
            cin >> x;
            graph[i].insert(x);
            Union(i, x);
        }

        rp(i, 1, n + 1) visited[i] = 0;

        int x = 0;
        rp(i, 1, n + 1)
        {
            if (visited[i] == 0)
            {
                ++x;
                visited[i] = x;
                dfs(i, 0, x);
            }
        }

        set<int> par;
        rp(i, 1, n + 1)
        {
            par.insert(find_parent(i));
        }

        int maxi = sz(par);

        cout << min((ans + 1), maxi) << " " << maxi << "\n";
    }

    return 0;
}