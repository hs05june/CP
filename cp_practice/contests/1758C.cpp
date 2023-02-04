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

int lpf[200007];

void seive(){
    for(int i = 2; i < 200005; i++){
        if(lpf[i]==0){
            lpf[i] = i;
            for(int j = i; j < 200005; j+=i){
                lpf[j] = i;
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
    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int a[n + 1] = {0};
        rep(i, 0, n)
        {
            a[i] = i;
        }
        a[1] = m;
        a[n] = 1;

        if(n%m!=0){
            cout << "-1\n";
            continue;
        }

        int x = n/m;
        deq primes;

        while(x>1){
            primes.pb(lpf[x]);
            x/=lpf[x];    
        }

        sort(all(primes));

        for(int i = 0; i < sz(primes); i++){
            a[m] = m*primes[i];
            m*=primes[i];
        }

        rep(i, 1, n)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}