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

        int n, k;
        cin >> n >> k;

        deq friends;
        deq graph[n + 1];

        rp(i, 0, k)
        {
            int x;
            cin >> x;
            friends.pb(x);
        }

        rp(i, 1, n)
        {
            int x, y;
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }

        int levels[n + 1], friend_levels[n + 1];
        bool visited[n + 1], friend_visited[n + 1];

        for (int i = 0; i <= n; i++)
        {
            levels[i] = 0;
            friend_levels[i] = 0;
            visited[i] = false;
            friend_visited[i] = false;
        }

        queue<int> bfs, friend_bfs;
        levels[1] = 0;
        bfs.push(1);

        while (!bfs.empty())
        {
            auto z = bfs.front();
            if (visited[z])
                continue;
            visited[z] = true;
            for (auto i : graph[z])
            {
                if (!visited[i])
                {
                    levels[i] = 1 + levels[z];
                    bfs.push(i);
                }
            }
            bfs.pop();
        }

        for (auto i : friends)
        {
            friend_levels[i] = 0;
            friend_visited[i] = true;
            friend_bfs.push(i);
        }

        while (!friend_bfs.empty())
        {
            int z = friend_bfs.front();
            for (auto i : graph[z])
            {
                if (!friend_visited[i] || friend_levels[i] > (1 + friend_levels[z]))
                {
                    friend_levels[i] = 1 + friend_levels[z];
                    friend_visited[i] = true;
                    friend_bfs.push(i);
                }
            }
            friend_bfs.pop();
        }

        bool check = false;
        rp(i, 2, n + 1)
        {
            if (graph[i].size() == 1 && levels[i] < friend_levels[i])
            {
                check = true;
                break;
            }
        }

        check ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}