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

int n, k;
int arr[5007];
int cold[5007], hot[5007];
int dp[5007][5007];

int solve(int in, int x)
{
    if (in > n)
        return 0;
    if (dp[in][x] != -1)
        return dp[in][x];
    if (arr[in] == arr[in - 1] || arr[in] == x)
    {
        return dp[in][x] = min(hot[arr[in]] + solve(in + 1, x), hot[arr[in]] + solve(in + 1, arr[in - 1]));
    }
    return dp[in][x] = min(cold[arr[in]] + solve(in + 1, arr[in - 1]), cold[arr[in]] + solve(in + 1, x));
}

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

        cin >> n >> k;
        rp(i, 1, n + 1) cin >> arr[i];
        rp(i, 1, k + 1) cin >> cold[i];
        rp(i, 1, k + 1) cin >> hot[i];

        rp(i, 0, n + 1)
        {
            rp(j, 0, k + 1)
            {
                dp[i][j] = -1;
            }
        }

        if (n == 1)
        {
            cout << cold[arr[1]] << "\n";
            continue;
        }

        cout << cold[arr[1]] + solve(2, 0) << "\n";
    }

    return 0;
}