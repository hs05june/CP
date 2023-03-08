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

        set<pii> ma[n + 1];

        pii edges[m];
        int ans[m];

        rp(i, 0, m)
        {
            cin >> edges[i].f >> edges[i].s;
            ma[edges[i].f].insert({edges[i].s, i});
            ma[edges[i].s].insert({edges[i].f, i});
            ans[i] = 0;
        }

        bool done = false;
        rp(i, 1, n + 1)
        {
            if (sz(ma[i]) < n - 1)
            {
                done = true;
                for (auto j : ma[i])
                {
                    ans[j.s] = 1;
                }
                break;
            }
        }

        if (done)
        {
            rp(i, 0, m)
            {
                if (ans[i] == 0)
                {
                    ans[i] = 2;
                }
            }
            cout << 2 << "\n";
            rp(i, 0, m)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
            continue;
        }

        for (auto i : ma[1])
        {
            ans[i.s] = 1;
        }

        auto k = *(ma[1].begin());
        ans[k.s] = 2;

        rp(i, 0, m)
        {
            if (ans[i] == 0)
            {
                ans[i] = 3;
            }
        }

        cout << "3\n";
        rp(i, 0, m)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}