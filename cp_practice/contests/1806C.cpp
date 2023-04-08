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

        int arr[2 * n];

        int ans = 0;

        rp(i, 0, 2 * n)
        {
            cin >> arr[i];
            ans += abs(arr[i]);
        }

        sort(arr, arr + n);

        if (n == 1)
        {
            cout << min(ans, abs(arr[0] - arr[1])) << "\n";
            continue;
        }

        if (n & 1)
        {
            cout << ans << "\n";
            continue;
        }

        int x = 0;
        if (n == 2)
        {
            rp(i, 0, 2 * n) x += abs(arr[i] - 2);
            ans = min(ans, x);
        }
        int sum = 0;
        x = LLONG_MAX;
        rp(i, 0, 2 * n)
        {
            sum += abs(arr[i] + 1);
        }
        rp(i, 0, 2 * n)
        {
            x = min(x, sum - abs(arr[i] + 1) + abs(arr[i] - n));
        }
        ans = min(ans, x);

        cout << ans << "\n";
    }

    return 0;
}