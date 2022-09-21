#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int a[m];

        set<pair<ll, ll>> s;
        map<ll, ll> cnt;

        for (int i = 1; i <= n; i++)
        {
            cnt.insert({i, 0});
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (auto i : cnt)
        {
            s.insert({i.second, i.first});
        }

        auto x = *(s.begin()), y = *(--s.end());

        while ((x.first + 2) <= (y.first - 1))
        {
            ll a = x.first, b = x.second, c = y.first, d = y.second;
            s.erase({a, b});
            s.insert({a + 2, b});
            s.erase({c, d});
            s.insert({c - 1, d});
            x = *(s.begin());
            y = *(--s.end());
        }

        ll ans = 0;

        for (auto i : s)
        {
            ans = max(ans, i.first);
        }
        cout << ans << "\n";
    }

    return 0;
}