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

        int arr[n + 1][m + 1], ans[n + 1];
        set<string> present;

        rp(i, 0, n + 1)
        {
            ans[i] = 0;
        }

        rp(i, 1, n + 1)
        {
            rp(j, 1, m + 1)
            {
                cin >> arr[i][j];
            }
        }

        rp(i, 1, n + 1)
        {
            char a[m + 1];
            rp(j, 1, m + 1)
            {
                a[arr[i][j]] = (char)(j + '0');
            }
            string str = "";
            rp(j, 1, m + 1)
            {
                str.pb(a[j]);
                present.insert(str);
            }
        }

        rp(i, 1, n + 1)
        {
            string a = "";
            rp(j, 1, m + 1)
            {
                a.pb((char)(arr[i][j] + '0'));
                if (present.count(a))
                {
                    ans[i]++;
                }
                else
                {
                    break;
                }
            }
        }

        rp(i, 1, n + 1)
        {
            cout << ans[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}