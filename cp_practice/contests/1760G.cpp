#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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

        int n, a, b;
        cin >> n >> a >> b;

        vector<pii> tree[n + 1];

        rp(i, 1, n)
        {
            int x, y, z;
            cin >> x >> y >> z;
            tree[x].pb({z, y});
            tree[y].pb({z, x});
        }

        mii levels[2];
        bool visited[2][n + 1];
        queue<int> bfs[2];
        set<int> distance[2];

        rp(i,0,2){
            rep(j,0,n){
                visited[i][j] = false;
            }
        }

        levels[0][a] = 0;
        visited[0][a] = true;
        levels[1][b] = 0;
        visited[1][b] = true;

        bfs[0].push(a);
        bfs[1].push(b);

        rp(i, 0, 2)
        {
            while (bfs[i].size())
            {
                int x = bfs[i].front();
                for (auto j : tree[x])
                {
                    if (!(visited[i][j.s]) && j.s != b)
                    {
                        visited[i][j.s] = true;
                        levels[i][j.s] = (levels[i][x] ^ j.f);
                        if (j.s != b)
                        {
                            distance[i].insert(levels[i][j.s]);
                        }
                        bfs[i].push(j.s);
                    }
                }
                bfs[i].pop();
            }
        }

        // rp(i,0,2){
        //     rep(j,1,n){
        //         cout << j << " " << levels[i][j] << endl;
        //     }
        //     cout << "\n";
        // }

        // rp(i,0,2){
        //     for(auto j : distance[i]){
        //         cout << j << "\n";
        //     }
        //     cout << "\n";
        // }

        bool ans = false;

        if (distance[1].count(0))
        {
            ans = true;
        }

        for (auto i : distance[1])
        {
            if (distance[0].count(i))
            {
                ans = true;
                break;
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}