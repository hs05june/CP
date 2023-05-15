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

int fibonacci[50];
int ans = 0;

bool solve(int h, int w, int x, int y)
{
    ans++;
    if (w == h)
        return true;
    if (w > h)
    {
        if (y >= h)
        {
            return solve(h, w - h, x, y - h);
        }
        else if (y < w - h)
        {
            return solve(h, w - h, x, y);
        }
    }
    else if (h > w)
    {
        if (x >= w)
        {
            return solve(h - w, w, x - w, y);
        }
        else if (x < h - w)
        {
            return solve(h - w, w, x, y);
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    fibonacci[0] = 1;
    fibonacci[1] = 1;

    rp(i, 2, 50)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    while (t--)
    {

        int n, x, y;
        cin >> n >> x >> y;

        ans = 0;

        int h = fibonacci[n], w = fibonacci[n + 1];

        solve(h, w, x - 1, y - 1) ? cout << "YES\n" : cout << "NO\n";
        // cout << ans << "\n";
    }

    return 0;
}