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

        mii cnt;
        set<pii> extra;

        rp(i, 0, n)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int used = 0, left = 0;
        bool ans = true;
        cout << cnt[0] << " ";
        used += cnt[0];
        if (cnt[0] > 1)
        {
            extra.insert({0, cnt[0] - 1});
        }
        for (int i = 1; i <= n; i++)
        {

            if (!ans)
            {
                cout << "-1 ";
                continue;
            }

            if (used < i)
            {
                cout << "-1 ";
                ans = false;
                continue;
            }

            used += cnt[i];
            if (cnt[i - 1] == 0)
            {
                if (extra.size() == 0)
                {
                    ans = false;
                    cout << "-1 ";
                    continue;
                }
                else
                {
                    auto z = *(extra.begin());
                    left += (i - 1 + z.f);
                    extra.erase(extra.begin());
                    if (z.s - 1 >= 1)
                    {
                        extra.insert({z.f, z.s - 1});
                    }
                }
            }
            if (cnt[i] > 1)
            {
                extra.insert({-i, cnt[i] - 1});
            }
            cout << left + cnt[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}