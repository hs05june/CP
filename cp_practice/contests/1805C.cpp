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

        vector<double> k;

        rp(i, 0, n)
        {
            double x;
            cin >> x;
            k.pb(x);
        }

        sort(all(k));

        rp(i, 0, m)
        {
            double a, b, c;
            cin >> a >> b >> c;
            double x;
            x = (b * b - 4 * a * c);
            double y = 4 * b * b - 4 * x;
            if (y <= 0)
            {
                cout << "NO\n";
            }
            else
            {
                double k1 = (2 * b + sqrtl(y)) / 2;
                double k2 = (2 * b - sqrtl(y)) / 2;
                if (k1 > k2)
                {
                    swap(k1, k2);
                }
                auto itr = upper_bound(all(k), k1);
                if (itr == k.end())
                {
                    cout << "NO\n";
                }
                else
                {
                    int z = itr - k.begin();
                    if (k[z] < k2)
                    {
                        cout << "YES\n";
                        cout << (int)(k[z]) << "\n";
                    }
                    else
                    {
                        cout << "NO\n";
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}