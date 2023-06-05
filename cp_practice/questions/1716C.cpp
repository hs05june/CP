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

        int arr[n][2];
        rp(j, 0, 2)
        {
            rp(i, 0, n) cin >> arr[i][j];
        }
        int diff[2][n][2];
        rp(i, 0, n)
        {
            rp(j, 0, 2)
            {
                diff[0][i][j] = arr[i][j] - i + 1;
                diff[1][n - 1 - i][j] = arr[n - 1 - i][j] - i;
            }
        }
        diff[0][0][0] = 0;
        int maxi[2][n][2];

        rp(j, 0, 2)
        {
            rp(i, 0, 2)
            {
                maxi[j][n - 1][i] = diff[j][n - 1][i];
            }
        }
        rp(k, 0, 2)
        {
            rep(i, n - 2, 0)
            {
                rp(j, 0, 2)
                {
                    maxi[k][i][j] = max(diff[k][i][j], maxi[k][i + 1][j]);
                }
            }
        }
        int ans = INT_MAX, spend = 0;
        int visited[n][2];
        rp(i, 0, n)
        {
            rp(j, 0, 2) visited[i][j] = 0;
        }
        int x = 0;
        pii start = {0, 0};
        visited[0][0] = 1;
        while (start.f != n - 1)
        {
            visited[start.f][start.s] = 1;
            int z = maxi[0][start.f + 1][start.s];
            int y = max(z - x, 0LL);
            z = (visited[start.f][(start.s + 1) % 2] == 0) ? maxi[1][start.f][(start.s + 1) % 2] : maxi[1][start.f + 1][(start.s + 1) % 2];
            int z1 = spend + y + n - 1 - start.f;
            y = max(z - z1, 0LL);
            int z2 = (visited[start.f][(start.s + 1) % 2] == 0) ? z1 + y + n - start.f : z1 + y + n - 1 - start.f;
            ans = min(ans, z2);
            if (visited[start.f][(start.s + 1) % 2] == 1)
            {
                start.f++;
                x += max(arr[start.f][start.s] - spend, 0LL);
                spend = max(spend + 1, arr[start.f][start.s] + 1);
            }
            else
            {
                start.s++;
                start.s %= 2;
                ++x;
                x += max(arr[start.f][start.s] - spend, 0LL);
                spend = max(spend + 1, arr[start.f][start.s] + 1);
            }
        }
        int z = max(spend + 1, arr[n - 1][start.s] + 1);
        z = max(z, arr[n - 1][(start.s + 1) % 2] + 1);
        ans = min(z, ans);
        cout << ans << "\n";
    }

    return 0;
}