#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
// #define int long long
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

int n, m;

bool check(vector<vector<int>> arr, int side)
{

    int pre[n + 1][m + 1];

    rep(i, 0, m) pre[0][i] = 0;
    rep(i, 0, n) pre[i][0] = 0;

    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (arr[i][j] >= side)
            {
                pre[i][j]++;
            }
        }
    }

    rep(i, side, n)
    {
        rep(j, side, m)
        {
            int sum = pre[i][j] + pre[i - side][j - side] - pre[i][j - side] - pre[i - side][j];
            if (sum >= side * side)
                return true;
        }
    }
    return false;
}

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

        cin >> n >> m;

        vector<int> a(m + 1, 0);
        vector<vector<int>> arr(n + 1, a);

        rep(i, 1, n)
        {
            rep(j, 1, m)
            {
                cin >> arr[i][j];
            }
        }

        int low = 1, high = min(n, m);

        while (high - low > 1)
        {
            int mid = (high + low) / 2;
            if (check(arr, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (check(arr, high))
        {
            cout << high << "\n";
        }
        else
        {
            cout << low << "\n";
        }
    }
    return 0;
}