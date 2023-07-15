#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define ld long double
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
    cin >> t;

    while (t--)
    {

        int n, k, x;
        cin >> n >> k >> x;

        string a;
        cin >> a;

        deq every;

        rp(i, 0, sz(a))
        {
            if (a[i] == 'a')
                every.pb(-1);
            else
            {
                int z = 0;
                while (i < sz(a) && a[i] == '*')
                {
                    z += k;
                    ++i;
                }
                --i;
                every.pb(z);
            }
        }

        deq num[sz(every)];
        int sum = 1;
        rep(i, sz(every) - 1, 0)
        {
            int z = 0;
            if (every[i] == -1)
            {
                num[i].pb(sum);
                continue;
            }
            rp(j, 0, every[i] + 1)
            {
                num[i].pb(z + sum);
                if (x <= (z + sum))
                    break;
                z += sum;
            }
            sum = num[i].back();
        }

        string ans = "";

        rp(i, 0, sz(every))
        {
            if (every[i] == -1)
            {
                ans.pb('a');
                continue;
            }
            auto itr = lower_bound(all(num[i]), x);
            int z = itr - num[i].begin();
            if (z == 0)
                continue;
            rp(j, 0, z) ans.pb('b');
            x -= num[i][z - 1];
        }

        cout << ans << "\n";
    }

    return 0;
}