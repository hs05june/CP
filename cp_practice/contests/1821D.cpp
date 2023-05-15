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

        int n, k;
        cin >> n >> k;

        int l[n], r[n];

        rp(i, 0, n) cin >> l[i];
        rp(i, 0, n) cin >> r[i];

        int total = 0, one = 0, ans = 0, used = 0, segs = 0;

        rp(i, 0, n)
        {
            total += (r[i] - l[i] + 1);
        }

        if (total < k)
        {
            cout << "-1\n";
            continue;
        }

        int maxi = 0;
        rp(i, 0, n)
        {
            if (used >= k && one == 0)
                break;
            if (used < k)
            {
                int x = min(r[i] - l[i] + 1, k - used);
                segs++;
                used += x;
                one += (l[i] == r[i]);
                maxi = l[i] + x - 1;
                ans = maxi + 2 * segs;
                if (maxi != r[i] && one != 0)
                {
                    int y = min(one, r[i] - maxi);
                    one -= y;
                    segs -= y;
                    maxi = maxi + y;
                    ans = maxi + 2 * segs;
                }
            }
            else if (one != 0 && l[i] != r[i])
            {
                int x = min(one, r[i] - l[i] + 1);
                segs++;
                segs -= x;
                one -= x;
                maxi = l[i] + x - 1;
                ans = min(maxi + 2 * segs, ans);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}