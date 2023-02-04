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

int spf[100007];

vector<int> primes;

void seive()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (spf[i] == 0)
        {
            primes.pb(i);
            for (int j = i; j <= 100000; j += i)
            {
                spf[j] = i;
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

    int t = 1;
    cin >> t;

    seive();

    // cout << sz(primes);

    while (t--)
    {

        int n;
        cin >> n;
        mii cnt,ele;

        bool ans = false;

        rp(i, 0, n)
        {
            int x;
            cin >> x;
            ele[x]++;
            if(ele[x]>=2){
                ans = true;
            }
            if (!ans)
            {
                // while (x != 1)
                // {
                //     int z = spf[x];
                //     cnt[z]++;
                //     if (cnt[z] >= 2)
                //     {
                //         ans = true;
                //         break;
                //     }
                //     while (x != 1 && (x % z) == 0)
                //     {
                //         x /= z;
                //     }
                // }
                int z = x;
                for(int i = 0; primes[i]*primes[i]<=x;i++){
                    if((x%primes[i])==0){
                        cnt[primes[i]]++;
                        while(z%primes[i]==0){
                            z/= primes[i];
                        }
                    }
                    if(cnt[primes[i]]>=2){
                        ans = true;
                        break;
                    }
                }
                if(!ans && z!=1){
                    cnt[z]++;
                    if(cnt[z]>=2){
                        ans = true;
                    }
                }
            }
        }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}