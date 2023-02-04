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

        ll n, q;
        cin >> n >> q;

        deque<ll> arr;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        deque<ll> preffix_sum;
        preffix_sum.push_back(0);

        for (int i = 0; i < n; i++)
        {
            preffix_sum.push_back(preffix_sum[i] + arr[i]);
        }

        while (q--)
        {
            ll x;
            cin >> x;

            if (x > preffix_sum.back())
            {
                cout << "-1\n";
                continue;
            }

            auto itr = lower_bound(preffix_sum.begin(), preffix_sum.end(), x);
            cout << itr - preffix_sum.begin() << "\n";
        }
    }

    return 0;
}