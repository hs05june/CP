#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY      \
    cin.tie(0); \
    cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
int M = 1000000007;
using namespace std;

signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n, q;
        cin >> n >> q;

        ll arr[n + 1] = {0};
        ll maxi = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (arr[maxi] < arr[i])
                maxi = i;
        }

        ll winner[n] = {0};
        winner[1] = arr[1] > arr[2] ? 1 : 2;

        for (int i = 2; i < n; i++)
        {
            winner[i] = arr[winner[i - 1]] > arr[i + 1] ? winner[i - 1] : (i + 1);
        }

        map<int, pii> m;

        for (int i = 1; i <= n; i++)
        {
            m[i] = {0, 0};
        }

        for (int i = 1; i < n; i++)
        {
            int ini = i, z = winner[i];
            while (i < n && z == winner[i])
            {
                ++i;
            }
            --i;
            m[winner[i]] = {ini, i};
        }
        while (q--)
        {
            ll i, k;
            cin >> i >> k;
            if (i == maxi)
            {
                if (k >= n)
                {
                    cout << k - n + 2 + m[maxi].second - m[maxi].first << "\n";
                }
                else
                {
                    if (k < m[maxi].first)
                        cout << 0 << "\n";
                    else
                        cout << k - m[maxi].first + 1 << "\n";
                }
            }
            else
            {
                if (m[i].first == 0 || k < m[i].first)
                    cout << "0\n";
                else if (k <= m[i].second)
                    cout << k - m[i].first + 1 << "\n";
                else
                    cout << m[i].second - m[i].first + 1 << "\n";
            }
        }
    }

    return 0;
}