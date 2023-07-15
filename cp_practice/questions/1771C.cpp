#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 31700;
using namespace std;

ll lpf[M+1];
deq primes;

void seive(){
    for(int i = 2; i <= M; i++){
        if(lpf[i] != 0)continue;
        primes.pb(i);
        for(int j = i; j <= M; j+=i){
            lpf[j] = i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    seive();

    int t = 1;
    cin >> t;

    while(t--){

        set<ll> cnt;
        int n;
        cin >> n;

        ll arr[n];
        rp(i,0,n) cin >> arr[i];

        bool ans = false;

        rp(i,0,n){
            ll x = arr[i];
            for(int j = 0; (j < sz(primes)) && ((primes[j] * primes[j]) <= x); j++){
                if(x <= M)break;
                if((x % primes[j]) == 0){
                    if(cnt.count(primes[j])){ans = true;break;}
                    cnt.insert(primes[j]);
                    while((x % primes[j]) == 0) x /= primes[j];
                }
            }
            if(x > M){
                if(cnt.count(x)){ans = true;break;}
                cnt.insert(x);
                continue;
            }
            while(x != 1){
                int z = lpf[x];
                if(cnt.count(z)){ans = true;break;}
                cnt.insert(z);
                while(x%z==0)x /= z;
            }
            if(ans)break;
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}