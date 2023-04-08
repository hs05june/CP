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
        string a;
        cin >> a;
        int dex = 0;
        char b = a[0];
        rp(i, 0, n)
        {
            if (b >= a[i])
            {
                b = a[i];
                dex = i;
            }
        }
        string c = "";
        c.pb(a[dex]);
        rp(i, 0, n)
        {
            if (i != dex)
            {
                c.pb(a[i]);
            }
        }
        cout << c << "\n";
    }

    return 0;
}