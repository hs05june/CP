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
        int n,m;
        cin >> n >> m;

        int a[n+1] = {0};

        rep(i,1,n){
            cin >> a[i];
        }
        int ans = 0;

        int pre[n+1] = {0};

        rep(i,1,m){
            pre[i] = a[i] + pre[i-1];
        }


        multiset<int> maxi;
        for(int i = m; i>0; i--){
            while (pre[i]<pre[m])
            {
                int z = *(--maxi.end());
                maxi.erase(--maxi.end());
                pre[m]-=(2*z);
                ans++;
            }
            if(a[i] > 0)maxi.insert(a[i]);
        }
        for(int i = m+1; i<=n; i++){
            pre[i] = a[i] + pre[i-1];
        }
        int x = 0;
        multiset<int> mini;
        for(int i = m+1; i<=n; i++){
            if(a[i]<0)mini.insert(a[i]);
            while((pre[i]+x)<pre[m]){
                int z = *(mini.begin());
                mini.erase(mini.begin());
                x-=(2*z);
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}