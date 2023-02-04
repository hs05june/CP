#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY      \
    cin.tie(0); \
    cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;

int parent[100007];
int sizes[100007];

void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    int x = find(a), y = find(b);
    if (sizes[x] > sizes[y])
        swap(x, y);

    parent[x] = y;
    sizes[y] += sizes[x];
}

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
    return ans;
}

signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            sizes[i] = 1;
            parent[i] = i;
        }
        int a[n], b[n], c[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            Union(a[i], b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++)

            ll ans = 0;

        set<int> fixed;
        for (int i = 0; i < n; i++)
        {
            if (c[i] != 0 || a[i] == b[i])
            {
                fixed.insert(find(a[i]));
                fixed.insert(find(b[i]));
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll x = find(i);
            if (!fixed.count(x))
            {
                ans++;
                fixed.insert(x);
            }
        }
        cout << power(2, ans, M) << "\n";
    }

    return 0;
}
