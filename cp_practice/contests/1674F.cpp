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
    while (t--)
    {

        int n, m, q;
        cin >> n >> m >> q;
        string a[n];

        rp(i, 0, n)
        {
            cin >> a[i];
        }

        int sum = 0;
        rp(i, 0, n)
        {
            for (auto j : a[i])
            {
                sum += (j == '*');
            }
        }

        int ans = 0;
        int x = 0;
        rp(i, 0, m)
        {
            rp(j, 0, n)
            {
                if (a[j][i] == '.' && x < sum)
                {
                    ans++;
                }
                ++x;
            }
        }

        pii last = (sum % n) == 0 ? make_pair((n - 1), (sum / n - 1)) : make_pair((sum % n - 1 + n) % n, (sum / n));
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            int sum1 = sum;
            if (a[x][y] == '*')
            {
                sum1--;
                a[x][y] = '.';
            }
            else
            {
                sum1++;
                a[x][y] = '*';
            }

            pii last1 = (sum1 % n) == 0 ? make_pair((n - 1), (sum1 / n - 1)) : make_pair((sum1 % n - 1 + n) % n, (sum1 / n));

            if (sum1 > sum)
            {
                if ((y > last1.s || (y == last1.s && x > last1.f)) && a[last1.f][last1.s] != '*')
                {
                    ans++;
                }
                else if ((a[last1.f][last1.s] == '*' && (y < last.s || (y == last.s && x <= last.f))))
                    ans--;
            }
            else if (sum1 < sum)
            {
                if ((y > last.s || (y == last.s && x > last.f)) && a[last.f][last.s] != '*')
                {
                    ans--;
                }
                else if (a[last.f][last.s] == '*' && (y < last1.s || (y == last1.s && x <= last1.f)))
                {
                    ans++;
                }
            }
            sum = sum1;
            last = last1;
            cout << ans << "\n";
        }
    }

    return 0;
}