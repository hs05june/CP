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

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int l, r, lc, rc, ans;
        bool same = true;
        n--;
        cin >> l >> r >> lc;
        rc = lc;
        ans = lc;
        cout << ans << "\n";
        pair<int, pii> left, right;
        left = {l, {lc, r}};
        right = {r, {rc, l}};
        map<pii, int> cost;
        cost[{l, r}] = lc;
        while (n--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (cost[{x, y}] == 0)
            {
                cost[{x, y}] = z;
            }
            else
            {
                cost[{x, y}] = min(cost[{x, y}], z);
            }
            if (x < left.f)
            {
                left = {x, {z, y}};
            }
            if (x == left.f && (z < (left.s).f || (z == (left.s).f && y >= (left.s).s)))
            {
                left = {x, {z, y}};
            }

            if (y > right.f)
            {
                right = {y, {z, x}};
            }
            if (y == right.f && (z < (right.s).f || (z == (right.s).f && x <= (right.s).s)))
            {
                right = {y, {z, x}};
            }

            ll mini = left.f;
            ll maxi = right.f;

            ans = LLONG_MAX;
            ans = min(ans, ((left.s).f + (right.s).f));

            if (cost[{mini, maxi}] != 0)
            {
                ans = min(ans, cost[{mini, maxi}]);
            }

            cout << ans << "\n";
        }
    }

    return 0;
}