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
#define lb(a, b) lower_bound((a).begin(), (a).end(), c)
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

        int cnt = 0;
        int a[n];
        set<int> ele;

        rp(i, 0, n)
        {
            cin >> a[i];
            ele.insert(a[i]);
            if (a[i] == 1)
                cnt++;
        }

        ll ans = 0;
        sort(a, a + n);
        for (int k = 1; k <= n; k++)
        {
            deq d;
            bool possible = true;
            int start = 0;
            int end = upper_bound(a, a + n, k) - a - 1;
            for (int i = 1; i <= k; i++)
            {
                if (start > end)
                {
                    possible = false;
                    break;
                }
                auto x = upper_bound(a + start, a + end + 1, k - i + 1) - a - 1;
                if (x < 0 || x < start)
                {
                    possible = false;
                    break;
                }
                end = x - 1;
                start++;
            }
            if (possible)
            {
                ans = max(ans, k);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}