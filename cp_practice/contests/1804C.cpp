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

        int n, x, p;
        cin >> n >> x >> p;
        int k = n - x;

        bool ans = false;

        rp(i, 1, min(2 * n + 1, p + 1))
        {
            int z = (i * (i + 1)) / 2;
            if ((z - k) >= 0)
            {
                if ((z - k) % n == 0)
                {
                    ans = true;
                    break;
                }
            }
        }

        ans ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}