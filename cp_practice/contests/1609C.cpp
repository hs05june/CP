//								ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

set<int> primes;
int visited[1000007];

void seive(){
    rep(i,2,1000000){
        if(visited[i]==0){
            visited[i] = 1;
            primes.insert(i);
            for(int j = 2*i; j <= 1000000; j+=i){
                visited[j] = 1;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;
    seive();

    while(t--){

        int n,e;
        cin >> n >> e;

        ll a[n+1] = {0};

        deq mere_primes;

        rep(i,1,n){
            cin >> a[i];
            if(primes.count(a[i])){
                mere_primes.push_back(i);
            }
        }
        ll ans = 0;
        for(auto i : mere_primes){
            ll pichhe = 0, agge = 0;
            ll x = 1,y=1;
            while((i-(x*e))>=1 && a[i-(x*e)]==1){
                pichhe++;++x;
            }
            while((i+(y*e))<=n && a[i+(y*e)]==1){
                agge++;++y;
            }
            ans += (((agge+1) * pichhe) + agge);
        }

        cout << ans << "\n";
    }

    return 0;}