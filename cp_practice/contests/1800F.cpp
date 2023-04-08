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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while (t--)
    {

        int n;
        cin >> n;

        string a[n];

        rp(i, 0, n)
        {
            cin >> a[i];
        }

        int ans = 0;
        int cnt[n][26];

        rp(i, 0, n)
        {
            rp(j, 0, 26) cnt[i][j] = 0;
            for (auto j : a[i])
                cnt[i][(int)(j - 'a')]++;
        }

        rp(j, 0, 26)
        {
            mii stored;
            rp(i, 0, n)
            {
                if (cnt[i][j] != 0)
                    continue;
                int test = 0, to_test = 0;

                rp(k, 0, 26)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    if (cnt[i][k] % 2 == 0)
                    {
                        test |= (1 << k);
                    }
                    else
                    {
                        to_test |= (1 << k);
                    }
                }

                stored[test]++;
                if (stored.count(to_test))
                {
                    ans += stored[to_test];
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}