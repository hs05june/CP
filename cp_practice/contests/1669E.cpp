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

int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        map<char, int> first, second;
        map<string, int> same;

        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;

            first[a[0]]++;
            second[a[1]]++;
            same[a]++;
        }

        ll ans = 0;

        for (auto i : first)
        {
            ans += (i.second * (i.second - 1) / 2);
        }
        for (auto i : second)
        {
            ans += (i.second * (i.second - 1) / 2);
        }
        for (auto i : same)
        {
            ans -= (i.second * (i.second - 1));
        }

        cout << ans << "\n";
    }

    return 0;
}