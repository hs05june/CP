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

    int cost1 = 1000000000000;
    int cost2 = 1000000000001;

    while (t--)
    {

        string a;
        cin >> a;

        int n = sz(a);

        int cnt[n + 2][2][2];
        cnt[0][1][0] = cnt[n + 1][1][0] = 0;
        cnt[0][1][1] = cnt[n + 1][1][1] = 0;
        cnt[0][0][0] = cnt[n + 1][0][0] = 0;
        cnt[0][0][1] = cnt[n + 1][0][1] = 0;

        rp(i, 1, n + 2)
        {
            cnt[i][0][0] = cnt[i - 1][0][0];
            cnt[i][0][1] = cnt[i - 1][0][1];
            if (a[i - 1] == '1')
            {
                cnt[i][0][1]++;
            }
            if (a[i - 1] == '0')
            {
                cnt[i][0][0]++;
            }
        }

        rep(i, n, 0)
        {
            cnt[i][1][0] = cnt[i + 1][1][0];
            cnt[i][1][1] = cnt[i + 1][1][1];
            if (a[i - 1] == '0')
            {
                cnt[i][1][0]++;
            }
            if (a[i - 1] == '1')
            {
                cnt[i][1][1]++;
            }
        }

        int ans = LLONG_MAX;

        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                ans = min(ans, (cnt[0][1][0] * cost2));
                continue;
            }
            if (i == n)
            {
                ans = min(ans, (cnt[n][0][1] * cost2));
                continue;
            }
            ans = min(ans, (cnt[i][0][1] + cnt[i + 1][1][0]) * cost2);
            if (a[i - 1] == '1' && a[i] == '0')
            {
                ans = min(ans, cost1 + cost2 * (cnt[i][1][0] - 1 + cnt[i][0][1] - 1));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}