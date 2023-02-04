//  ੴ  ਵਾਹਿਗੁਰੂ

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define lb(a, b, c) lower_bound(a, b, c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
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
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        ll a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int forw[n + 2] = {0};

        for (int i = 1; i <= n; i++)
        {
            forw[i] = forw[i - 1] + a[i - 1];
        }

        map<ll, ll> maxis;
        for (int i = 1; i <= n; i++)
        {
            ll maxi = INT_MIN;
            for (int j = i; j <= n; j++)
            {
                maxi = max(maxi, forw[j] - forw[j - i]);
            }
            maxis[i] = maxi;
        }

        ll ans[n + 1] = {0};
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[i] = max(ans[i], maxis[j] + k * min(j, i));
            }
        }

        for (int i = 0; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}