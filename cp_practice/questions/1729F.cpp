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

        string a;
        cin >> a;

        int n = sz(a), w, m;
        cin >> w >> m;

        deq store[9];

        int preffix[n + 1];
        preffix[0] = 0;

        rp(i, 1, n + 1)
        {
            preffix[i] = preffix[i - 1] + (int)(a[i - 1] - '0');
        }

        rp(i, w, n + 1)
        {
            int x = (preffix[i] - preffix[i - w]);
            store[(x % 9)].pb(i - w + 1);
        }

        while (m--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int y = (preffix[r] - preffix[l - 1]);
            y %= 9;
            set<pii> ans;
            rp(i, 0, 9)
            {
                if (store[i].empty())
                    continue;
                int z = y * i;
                z %= 9;
                int x = (k % 9 - z % 9 + 9) % 9;
                int left = store[i][0];
                if (x != i)
                {
                    if (!(store[x].empty()))
                        ans.insert({left, store[x][0]});
                }
                if (x == i)
                {
                    if (store[i].size() >= 2)
                        ans.insert({store[i][0], store[i][1]});
                }
            }
            if (ans.empty())
            {
                cout << "-1 -1\n";
            }
            else
            {
                cout << (*(ans.begin())).f << " " << (*(ans.begin())).s << "\n";
            }
        }
    }

    return 0;
}