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

int parent[100007][70];
int visited[100007];
deq graph[100007];
void dfs(int n, int par)
{
    parent[n][0] = par;
    for (auto j : graph[n])
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            dfs(j, n);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;

    rp(i, 0, n + 1) visited[i] = 0;

    rp(i, 0, n-1)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    rp(i, 1, n + 1)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i, i);
        }
    }

    rp(j, 1, 10)
    {
        rp(i, 1, n + 1)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    while(m--){
        int x,y;
        cin >> x >> y;
        int ans = x;
        rp(i,0,10){
            if((y & (1<<i)) != 0){
                ans = parent[ans][i];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}