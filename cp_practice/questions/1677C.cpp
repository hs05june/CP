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

int visited[100007];
int graph[100007], parent[100007], Size[100007];

int Find(int n)
{
    if (n == parent[n])
        return n;
    return parent[n] = Find(parent[n]);
}

void Union(int x, int y)
{
    int a = Find(x), b = Find(y);
    if (a == b)
        return;
    if (Size[a] > Size[b])
        swap(a, b);
    parent[a] = b;
    Size[b] += Size[a];
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

        rp(i, 0, n + 1)
        {
            visited[i] = 0;
            parent[i] = 0;
            graph[i] = 0;
            Size[i] = 1;
            parent[i] = i;
        }

        int a[n + 1], b[n + 1];
        a[0] = b[0] = 0;

        rp(i, 1, n + 1) cin >> a[i];
        rp(i, 1, n + 1) cin >> b[i];

        rp(i, 1, n + 1)
        {
            graph[a[i]] = b[i];
            Union(a[i], b[i]);
        }
        int maxi = n, mini = 1;
        set<pii> values;
        rp(i, 1, n + 1)
        {
            int par = Find(i);
            values.insert({-Size[par], par});
        }
        int ans = 0;
        for (auto i : values)
        {
            if ((-i.f) == 1)
                break;
            int siz = (-i.f) % 2 == 0 ? (-i.f) - 1 : (-i.f) - 2;
            int x = maxi;
            rp(j, 0, siz)
            {
                ans += abs(maxi - mini);
                if (j % 2 == 0)
                    maxi--;
                else
                    mini++;
            }
            ans += abs(x - mini);
            mini++;
        }
        cout << ans << "\n";
    }

    return 0;
}