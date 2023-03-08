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
const ll M = 998244353;
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

        int l, r;
        cin >> l >> r;

        int ans = 0, x = l;

        while ((x) <= r)
        {
            ans++;
            x *= 2;
        }

        int factor = power(2, ans - 1, M);
        int ans1 = 0;
        ans1 += ((r / factor) - l + 1);

        if (factor >= 2)
        {
            int z = (factor / 2) * 3;
            int y = r / z;
            if (y >= l)
            {
                ans1 = ((ans1 % M) + (((y - l + 1) % M) * ((ans - 1) % M)) % M) % M;
            }
        }

        cout << ans << " " << (ans1 % M) << "\n";
    }

    return 0;
}