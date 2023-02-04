#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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
    return ans % mod;
}

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod) % mod;
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

        int n;
        cin >> n;

        string a[2];

        cin >> a[0] >> a[1];

        int x1 = LLONG_MAX, x2 = -1;

        rp(i, 0, n)
        {
            if (a[0][i] == 'B')
            {
                x1 = min(x1, i);
                x2 = max(x2, i);
            }
            if (a[1][i] == 'B')
            {
                x1 = min(x1, i);
                x2 = max(x2, i);
            }
        }

        bool visited[2][n] = {false};

        rp(i, 0, n)
        {
            visited[0][i] = visited[1][i] = false;
        }

        int x = x1, y = 0;

        if (a[y][x] == 'B')
        {
            visited[y][x] = true;
            while (x != x2)
            {
                if (a[(y + 1) % 2][x] == 'B' && visited[(y + 1) % 2][x] == false)
                {
                    y = (y + 1) % 2;
                    visited[y][x] = true;
                }
                else if (x + 1 < n && a[y][x + 1] == 'B' && visited[y][x+1] == false)
                {
                    ++x;
                    visited[y][x] = true;
                }
                else
                {
                    break;
                }
            }
            if(a[(y+1)%2][x]=='B'){
                visited[(y+1)%2][x] = true;
            }
        }
        bool ans = true;

        rp(i, 0, n)
        {
            if ((a[0][i] == 'B' && !visited[0][i]) || (a[1][i] == 'B' && !visited[1][i]))
            {
                ans = false;
                break;
            }
        }
        if (!ans)
        {
            x = x1;
            y = 1;
            rp(i, 0, n)
            {
                visited[0][i] = visited[1][i] = false;
            }
            if (a[y][x] == 'B')
            {
                visited[y][x] = true;
                while (x != x2)
                {
                    if (a[(y + 1) % 2][x] == 'B' && visited[(y + 1) % 2][x] == false)
                    {
                        y = (y + 1) % 2;
                        visited[y][x] = true;
                    }
                    else if (x + 1 < n && a[y][x + 1] == 'B' && visited[y][1+x] == false)
                    {
                        ++x;
                        visited[y][x] = true;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a[(y+1)%2][x]=='B'){
                visited[(y+1)%2][x] = true;
            }
            }
            ans = true;
            rp(i, 0, n)
            {
                if ((a[0][i] == 'B' && !visited[0][i]) || (a[1][i] == 'B' && !visited[1][i]))
                {
                    ans = false;
                    break;
                }
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}