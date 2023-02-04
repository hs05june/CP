//							  ੴ  ਵਾਹਿਗੁਰੂ

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "3\n";
    }
    else if (n == 2)
    {
        cout << "5\n";
    }
    else if (n == 3)
    {
        cout << "7\n";
    }

    else
    {
        n -= 4;

        if (n % 3 == 1)
        {
            cout << 4 * (n / 3) + 9 << "\n";
        }
        if (n % 3 == 2)
        {
            cout << 4 * (n / 3) + 11 << "\n";
        }
        if (n % 3 == 0)
        {
            cout << 4 * (n / 3) + 8 << "\n";
        }
    }
    return 0;
}