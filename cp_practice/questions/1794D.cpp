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

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod) % mod;
}

int factorial[5007], factorial_inv[5007];
int dp[4500][2500];
mii cnt;
deq uniq_primes;

bool check_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    factorial[0] = 1;
    factorial_inv[0] = modInverse(factorial[0], M) % M;

    rp(i, 1, 5005)
    {
        factorial[i] = (i % M * factorial[i - 1] % M) % M;
        factorial_inv[i] = modInverse(factorial[i], M) % M;
    }
    while (t--)
    {
        int n;
        cin >> n;

        int arr[2 * n];
        set<int> primes, uniq;
        int maxi = 0;
        rp(i, 0, 2 * n)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            cnt[arr[i]]++;
        }

        for (auto i : cnt)
            if (check_prime(i.f))
                uniq_primes.pb(i.f);
        if (sz(uniq_primes) < n)
        {
            cout << "0\n";
            continue;
        }

        int ans = factorial[n] % M;

        for (auto i : cnt)
        {
            if (!check_prime(i.f))
            {
                ans = (ans % M * factorial_inv[i.s] % M) % M;
            }
        }
        int siz = sz(uniq_primes);
        rp(i, 1, n + 1) dp[siz][i] = 0;

        dp[siz][0] = 1;

        for (int i = siz - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = 0;
                dp[i][j] = (dp[i + 1][j] % M * factorial_inv[cnt[uniq_primes[i]]] % M) % M;
                if (j - 1 >= 0)
                {
                    dp[i][j] = (dp[i][j] % M + (dp[i + 1][j - 1] % M * factorial_inv[cnt[uniq_primes[i]] - 1] % M) % M) % M;
                }
            }
        }

        cout << (ans % M * dp[0][n] % M) % M << "\n";
    }

    return 0;
}