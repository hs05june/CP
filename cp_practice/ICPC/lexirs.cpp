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

int n;
ll dp[507];
ll points[507];
string a;

ll solve(ll index, char x,ll z)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    ll ans = 0;
    if(z!=index)ans = max(ans,solve(index + 1, x,z));

    if (x <= a[index])
    {
        for (ll i = 1; i < n-index; i++)
        {
                ans = max(ans, points[i] + solve(index + i, a[index],z));
        }
    }
    return dp[index] = ans;
}

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        memset(dp, -1, sizeof(dp));
        cin >> n;
        cin >> a;

        for (int i = 1; i <= n; i++)
        {
            cin >> points[i];
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, a[i],i));
        }
        cout << ans << "\n";
       
    }

    return 0;
}