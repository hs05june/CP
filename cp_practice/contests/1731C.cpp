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

long long subarrayXor(int arr[], int n, int m, int x)
{
    long long ans = 0;
    int xorArr[n] = {0};

    int mp[(1 << (x + 1))] = {0};

    xorArr[0] = arr[0];

    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];

    for (int i = 0; i < n; i++)
    {

        int tmp = m ^ xorArr[i];

        ans = ans + ((long long)mp[tmp]);

        if (xorArr[i] == m)
            ans++;

        mp[xorArr[i]]++;
    }

    return ans;
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

        int s = 0;
        int ans = n * (n + 1) / 2;
        int arr[n];
        int x = 0, i = 0;

        while (n >= (1 << i))
        {
            if (((1 << i) & n) != 0)
            {
                x = i;
            }
            ++i;
        }
        rp(i, 0, n)
        {
            cin >> arr[i];
        }
        for (int i = 0; i * i < (1 << (x + 1)); i++)
        {
            ans -= subarrayXor(arr, n, i * i, x);
        }
        cout << ans << "\n";
    }

    return 0;
}