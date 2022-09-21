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

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        ll n, k;
        cin >> n >> k;

        string a;
        cin >> a;

        ll cnt = 0;
        deq index;

        for (ll i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                cnt++;
                index.push_back(i);
            }
        }

        ll ans = 11 * cnt;
        if (cnt == 1)
        {
            if (n - 1 - index[index.size() - 1] <= k)
            {
                ans -= 10;
            }
            else if (index[0] <= k)
            {
                ans--;
            }
        }
        else if (cnt >= 2)
        {
            if (n - 1 - index[index.size() - 1] <= k)
            {
                k -= (n - 1 - index[index.size() - 1]);
                ans -= 10;
            }
            if (index[0] <= k)
            {
                k -= index[0];
                ans--;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}