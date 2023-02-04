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

int cnt[200007];

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

        int a[n], b[n];

        rep(i, 0, n) cnt[i] = 0;
        rp(i, 0, n) cin >> a[i];
        rp(i, 0, n) cin >> b[i];

        bool ans = true;

        if (a[n - 1] != b[n - 1])
        {
            cout << "NO\n";
            continue;
        }

        int i = n - 2, j = n - 2;
        while (i >= 0 && j >= 0)
        {
            if (a[i] == b[j])
            {
                --i;
                --j;
            }
            else if (b[j] == b[j + 1])
            {
                cnt[b[j]]++;
                --j;
            }
            else if (cnt[a[i]] > 0)
            {
                cnt[a[i]]--;
                --i;
            }
            else
            {
                ans = false;
                break;
            }
        }

        while (i >= 0)
        {
            if (cnt[a[i]] <= 0)
            {
                ans = false;
                break;
            }
            cnt[a[i]]--;
            --i;
        }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}