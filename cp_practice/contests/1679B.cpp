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

        int n,
        q;
    cin >> n >> q;

    ll arr[n], sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    set<int> changed;
    bool all_set = false;
    ll z = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            if (!all_set || changed.count(x))
            {
                sum = sum - arr[x - 1] + y;
                arr[x - 1] = y;
                cout << sum << "\n";
            }
            else
            {
                sum = sum - z + y;
                arr[x - 1] = y;
                cout << sum << "\n";
                changed.insert(x);
            }
        }
        else if (t == 2)
        {
            ll x;
            cin >> x;
            sum = n * x;
            all_set = true;
            z = x;
            cout << sum << "\n";
            changed.clear();
        }
    }

    return 0;
}