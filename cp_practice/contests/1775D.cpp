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

int levels[600007], visited[600007], arr[300007];
map<int, deq> index;
deq graph[600007];

void seive(int maxi, int n)
{
    bool visited[maxi + 1];

    rp(i, 0, maxi + 1)
    {
        visited[i] = false;
    }
    int x = 1;

    for (int i = 2; i <= maxi; i++)
    {
        if (!(visited[i]))
        {
            for (int j = i; j <= maxi; j += i)
            {
                visited[j] = true;
                if (index.count(j))
                {
                    for (auto k : index[j])
                    {
                        graph[n + x].pb(k);
                        graph[k].pb(n + x);
                    }
                }
            }
            ++x;
        }
    }
}

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    levels[n] = 0;
    visited[n] = 1;

    while (!(q.empty()))
    {
        int x = q.front();
        q.pop();

        for (auto j : graph[x])
        {
            if (visited[j] == 0)
            {
                visited[j] = 1;
                levels[j] = 1 + levels[x];
                q.push(j);
            }
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

        arr[0] = 0;

        rp(i, 1, n + 1)
        {
            cin >> arr[i];
            arr[0] = max(arr[0], arr[i]);
            index[arr[i]].pb(i);
        }

        seive(arr[0], n);
        int a, b;
        cin >> a >> b;

        bfs(a);

        if (visited[b] == 0)
        {
            cout << "-1\n";
            continue;
        }

        deq path;
        queue<int> q;
        path.pb(b);
        while (levels[b] != 0)
        {
            bool found = false;
            for (auto j : graph[b])
            {
                if (visited[j] == 1 && levels[j] == levels[b] - 1)
                {
                    if (j <= n)
                        path.pb(j);
                    found = true;
                    b = j;
                    break;
                }
            }
        }

        cout << sz(path) << "\n";
        reverse(all(path));
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}