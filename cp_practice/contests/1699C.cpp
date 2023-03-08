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

        int arr[n];

        rp(i, 0, n)
        {
            int x;
            cin >> x;
            arr[x] = i;
        }

        deq ans;

        int mini = arr[0], maxi = arr[0];

        rp(i, 1, n)
        {
            if (!(arr[i] >= mini && arr[i] <= maxi))
            {
                mini = min(arr[i], mini);
                maxi = max(arr[i], maxi);
                continue;
            }
            int x = maxi - mini - (i - 1);
            ans.pb(x);
        }

        int cnt = 1;

        for (auto i : ans)
        {
            cnt = ((cnt % M) * (i % M)) % M;
        }

        cout << cnt << "\n";
    }

    return 0;
}