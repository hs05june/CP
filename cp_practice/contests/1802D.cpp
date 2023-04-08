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

        int n;
        cin >> n;

        int ans = LLONG_MAX;
        vector<pii> pehle;
        deq arr;

        rp(i, 0, n)
        {
            int x,y;
            cin >> x >> y;
            pehle.pb({x, y});
            arr.pb(y);
        }

        mii cnt;
        sort(all(arr));
        sort(all(pehle));
        int maxi = 0;
        for (int i = sz(pehle) - 1; i >= 0; i--)
        {
            if (i + 1 < sz(pehle))
            {
                maxi = max(maxi, pehle[i + 1].s);
            }
            int diff = LLONG_MAX;
            int x = pehle[i].f;
            auto itr = lower_bound(all(arr), x);
            int z = itr - arr.begin();

            if (z < n)
            {
                if ((arr[z] == pehle[i].s && cnt[pehle[i].s] >= 2) || arr[z] != pehle[i].s)
                {
                    diff = min(abs(max(maxi,arr[z]) - x), diff);
                }
                else if (z + 1 < n)
                {
                    diff = min(abs(max(arr[z + 1],maxi) - x), diff);
                }
            }
            if (z - 1 >= 0)
            {
                if ((arr[z - 1] == pehle[i].s && cnt[pehle[i].s] >= 2) || arr[z - 1] != pehle[i].s)
                {
                    diff = min(abs(max(arr[z - 1],maxi) - x), diff);
                }
                else if (z - 2 >= 0)
                {
                    diff = min(abs(max(arr[z - 2],maxi) - x), diff);
                }
            }
            ans = min(ans, diff);
        }

        cout << ans << "\n";
    }

    return 0;
}