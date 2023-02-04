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
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

// int a[200007];
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
        int a[n + 1] = {0};
        ll max_bit = -1;

        map<int, int> cnt;
        rep(i, 1, n)
        {
            cin >> a[i];
            cnt[a[i]]++;
            int j = 0;
            while (a[i] <= (1 << j))
            {
                if ((a[i] & (1 << j)) != 0)
                {
                    max_bit = max(j, max_bit);
                }
                ++j;
            }
        }
        ll maxi = *max_element(a, a + n + 1);
        deq ans;
        ans.pb(maxi);
        ll OR = maxi;
        cnt[maxi]--;
        for (int i = 0; i < 31 && i < (n - 1); i++)
        {
            ll z = OR;
            ll x;
            rep(j, 1, n)
            {
                if (cnt[a[j]] > 0)
                {
                    x = a[j];
                    break;
                }
            }
            rep(j, 1, n)
            {
                if (((OR | a[j]) > z) && (cnt[a[j]] > 0))
                {
                    z = (OR | a[j]);
                    x = a[j];
                }
            }
            OR |= x;
            cnt[x]--;
            ans.pb(x);
        }
        for (auto i : cnt)
        {
            rp(j, 0, i.s)
            {
                ans.pb(i.f);
            }
        }
        for (auto i : ans)
            cout << i << " ";
        cout << '\n';
    }

    return 0;
}