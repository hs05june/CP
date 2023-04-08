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

deq graph[100007];
int visited[100007], levels[100007][2];

void dfs(int n, int parent, int index)
{
    levels[n][index] = 1 + levels[parent][index];
    for (auto i : graph[n])
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i, n, index);
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

        int n;
        cin >> n;

        rp(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        if (n == 1)
        {
            cout << "1\n";
            continue;
        }

        int d1 = 1, d2 = 1;
        levels[0][0] = levels[0][1] = -1;
        visited[1] = 1;
        dfs(1, 0, 0);
        int maxi = levels[1][0];
        rp(i, 1, n + 1)
        {
            if (levels[i][0] > maxi)
            {
                maxi = levels[i][0];
                d1 = i;
            }
            levels[i][0] = 0;
        }
        rp(i, 0, n + 1) visited[i] = 0;
        visited[d1] = 1;
        dfs(d1, 0, 0);
        maxi = levels[1][0];
        rp(i, 1, n + 1)
        {
            if (levels[i][0] > maxi)
            {
                maxi = levels[i][0];
                d2 = i;
            }
        }
        rp(i, 0, n + 1) visited[i] = 0;
        visited[d2] = 1;
        dfs(d2, 0, 1);

        int ans[n + 1] = {0};

        rp(i, 1, n + 1) ans[i] = 0;

        rp(i, 1, n + 1)
        {
            int x = max(levels[i][0], levels[i][1]);
            ans[x + 1]++;
        }

        rp(i, 1, n + 1)
        {
            ans[i] += ans[i - 1];
        }

        rp(i, 1, n + 1)
        {
            cout << min(1 + ans[i], n) << " ";
        }
    }

    return 0;
}