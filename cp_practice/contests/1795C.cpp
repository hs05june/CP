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

        int a[n + 1] = {0}, b[n + 1] = {0};

        rp(i, 1, n + 1)
        {
            cin >> a[i];
        }
        rp(i, 0, n)
        {
            cin >> b[i];
        }

        deq pref(n + 2, 0);
        pref[n + 1] = LLONG_MAX;
        pref[0] = 0;

        int sum[n + 2], ans[n + 2];
        rp(i, 0, n + 2)
        {
            sum[i] = 0;
            ans[i] = 0;
        }

        rp(i, 1, n + 1)
        {
            pref[i] = pref[i - 1] + b[i - 1];
        }

        rp(i, 1, n + 1)
        {
            int x = a[i] + pref[i - 1];
            sum[i - 1]--;
            auto itr = lower_bound(all(pref), x);
            int z = itr - pref.begin();
            if (x == pref[z])
            {
                sum[z]++;
            }
            else
            {
                sum[z - 1]++;
                ans[z] += (x - pref[z - 1]);
            }
        }

        rep(i, n, 0)
        {
            sum[i] += sum[i + 1];
        }

        rp(i, 1, n + 1)
        {
            cout << (ans[i] + (sum[i] * b[i - 1])) << " ";
        }

        cout << "\n";
    }

    return 0;
}