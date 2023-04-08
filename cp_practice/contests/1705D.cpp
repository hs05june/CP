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
        string a, b;
        cin >> a >> b;
        int cnt1 = 0, cnt2 = 0;

        deq onea, oneb;
        if (a[0] == '1')
            onea.pb(0);
        if (b[0] == '1')
            oneb.pb(0);
        rp(i, 1, n)
        {
            if (a[i] != a[i - 1])
            {
                onea.pb(i);
            }
            if (b[i] != b[i - 1])
            {
                oneb.pb(i);
            }
        }

        if (a[0] != b[0] || a[n - 1] != b[n - 1] || sz(onea) != sz(oneb))
        {
            cout << "-1\n";
            continue;
        }

        int ans = 0;

        rp(i, 0, sz(onea))
        {
            ans += abs(onea[i] - oneb[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}