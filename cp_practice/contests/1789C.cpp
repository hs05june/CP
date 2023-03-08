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
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int cnt[n + m + 1] = {0};

        rp(i, 0, n + m + 1) cnt[i] = m + 1;

        int a[n + 1];
        pii b[m + 1];

        deq next_insert[n + m + 1];

        rp(i, 1, n + 1)
        {
            cin >> a[i];
            cnt[a[i]] = 0;
        }

        rp(i, 1, m + 1)
        {
            cin >> b[i].f >> b[i].s;
            cnt[b[i].s] = min(i, cnt[b[i].s]);
            next_insert[b[i].s].pb(i);
        }

        rp(i, 1, m + 1)
        {
            int x = a[b[i].f];
            auto itr = lower_bound(all(next_insert[x]), i);
            if (itr == next_insert[x].end())
            {
                cnt[x] += (m + 1 - i);
            }
            else
            {
                cnt[x] += ((*itr) - i);
            }
            a[b[i].f] = b[i].s;
        }

        int ans = 0;
        rp(i, 1, n + m + 1)
        {
            ans += (((m * (m + 1)) / 2) - ((cnt[i] * (cnt[i] - 1)) / 2));
        }
        cout << ans << "\n";
    }

    return 0;
}