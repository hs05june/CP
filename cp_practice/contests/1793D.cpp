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
    // cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int arr1[n + 1], arr2[n + 1];

        int index1[n + 1], index2[n + 1];

        index1[0] = 0;
        index2[0] = 0;

        rp(i, 1, n + 1)
        {
            cin >> arr1[i];
            index1[arr1[i]] = i;
        }
        rp(i, 1, n + 1)
        {
            cin >> arr2[i];
            index2[arr2[i]] = i;
        }

        int ans = 0;
        int x = 1;

        int l = index1[1], r = index2[1];

        if (l > r)
        {
            swap(l, r);
        }

        int z1 = (n - r), z2 = (l - 1);

        ans += (z1 * (z1 + 1)) / 2;
        ans += (z2 * (z2 + 1)) / 2;
        ans+=((r-l-1)*(r-l))/2;
        ++x;
        // cout << ans << "\n";
        while (x <= n)
        {
            // cout << x << " " << ans << "\n";
            int i1 = index1[x], i2 = index2[x];
            if ((i1 >= l && i1 <= r) || (i2 >= l && i2 <= r))
            {
                ++x;
                l = min(l, min(i1, i2));
                r = max(r, max(i1, i2));
                continue;
            }
            if (i1 > i2)
            {
                swap(i1, i2);
            }

            if (i2 <= l)
            {
                int x1 = l - i2;
                int x2 = n - r + 1;
                ans+=(x1*x2);
            }
            else if (i1 >= r)
            {
                int x1 = l;
                int x2 = i1-r;
                ans+=(x1*x2);
            }
            else
            {
                int x1 = l-i1;
                int x2 = i2 - r;
                ans+=(x1*x2);
            }
            l = min(l, min(i1, i2));
            r = max(r, max(i1, i2));
            ++x;
        }

        cout << ans+1 << "\n";
    }

    return 0;
}