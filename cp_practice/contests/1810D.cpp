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

        int mini = LLONG_MIN, maxi = LLONG_MAX;

        while (n--)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                int a, b, c;
                cin >> a >> b >> c;
                int x1, y1;
                if (c == 1)
                {
                    x1 = 1;
                    y1 = a;
                }
                else
                {
                    x1 = (c - 2) * (a - b) + a + 1;
                    y1 = (c - 1) * (a - b) + a;
                }
                if (x1 > maxi || y1 < mini)
                {
                    cout << "0 ";
                }
                else
                {
                    cout << "1 ";
                    mini = max(mini, x1);
                    maxi = min(maxi, y1);
                }
            }
            else if (x == 2)
            {
                int a, b;
                cin >> a >> b;
                int x1, y1;
                if (a >= mini)
                {
                    x1 = 1;
                }
                else
                {
                    int z = mini - a;
                    x1 = ceil(double(z) / double(a - b)) + 1;
                }
                if (a >= maxi)
                {
                    y1 = 1;
                }
                else
                {
                    int z = maxi - a;
                    y1 = ceil(double(z) / double(a - b)) + 1;
                }
                if (x1 == y1)
                {
                    cout << x1 << " ";
                }
                else
                {
                    cout << "-1 ";
                }
            }
        }

        cout << "\n";
    }

    return 0;
}