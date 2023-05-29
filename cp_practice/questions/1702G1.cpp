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
int tim;
set<int> check;
int euler[400010], sums[200007];
deq graph[200007];

int calculate_sums(int n, int par)
{
    int ans = 0;
    for (auto i : graph[n])
    {
        if (i == par)
            continue;
        ans += calculate_sums(i, n);
    }
    if (check.count(n))
        ans++;
    return sums[n] = ans;
}

void dfs(int n, int par)
{
    euler[tim] = n;
    tim++;

    for (auto i : graph[n])
    {
        if (i == par)
            continue;
        if (sums[i] > 0)
        {
            dfs(i, n);
        }
    }

    euler[tim] = par;
    tim++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int m;
        cin >> m;
        tim = 0;
        check.clear();
        rp(i, 0, 2 * n) euler[i] = 0;
        rp(i, 0, n + 1) sums[i] = 0;
        rp(i, 0, m)
        {
            int x;
            cin >> x;
            check.insert(x);
        }
        set<int> visit, need;
        int fg = calculate_sums(*(check.begin()), 0);
        dfs(*(check.begin()), 0);
        bool ans = false;
        int start = 0, index[n + 1];
        rp(i, 0, 2 * n)
        {
            int x = euler[i];
            if (visit.count(x))
            {
                bool squeeze = true;
                int k = index[x];
                rp(h, start, k)
                {
                    visit.erase(euler[h]);
                    need.erase(euler[h]);
                }
                start = index[x] + 1;
                index[x] = i;
                continue;
            }
            index[x] = i;
            visit.insert(x);
            if (check.count(x))
                need.insert(x);
            if (sz(check) == sz(need))
            {
                ans = true;
                break;
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}