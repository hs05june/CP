#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

deq primes;
void seive()
{
    bool check[1000];

    rp(i, 0, 1000)
    {
        check[i] = true;
    }

    for (int i = 2; i < 1000; i++)
    {
        if (check[i])
        {
            primes.pb(i);
            for (int j = i; j < 1000; j += i)
            {
                check[j] = false;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    seive();

    while (t--)
    {

        int n;
        cin >> n;

        int a[n];

        mii cnt;

        rp(i, 0, n)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        bool check = true;

        for (auto i : cnt)
        {
            if (i.s > 1)
                check = false;
        }

        if (!check)
        {
            cout << "NO\n";
            continue;
        }

        bool ans = true;

        for(int i : primes){
            int remainder[i];
            rp(j,0,i)remainder[j] = 0;
            for(int j = 0; j < n; j++){
                remainder[(a[j]%i)]++;
            }
            
            bool check = false;
            rp(j,0,i){
                if(remainder[j]<2){
                    check = true;
                }
            }
            if(!check){
                ans = false;
                break;
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;
}