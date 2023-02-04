//							  ੴ  ਵਾਹਿਗੁਰੂ 

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
const ll M = 998244353;
using namespace std;

ll factorials[65];

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;
    }

void calculate_factorials(){
    factorials[0] = 1; factorials[1] = 1;

    rep(i,1,60){
        factorials[i] = ((factorials[i-1]%M) * 1LL * (i%M))%M;
    }
} 
ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;
}

ll first(int n);ll second(int n);

ll nCr(int n,int k,ll mod){
    return (((factorials[n]%mod) * 1LL * (modInverse(factorials[k],mod)%mod))%mod * 1LL * (modInverse(factorials[n-k],mod)%mod)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;
    calculate_factorials();

    while(t--){
        int n;
        cin >> n;

        cout << first(n) << " " << second(n) << " 1\n";
    }

    return 0;}

ll first(int n){
    if(n<=2)return 1LL;
    return (nCr(n-1,n/2,M)%M + second(n-2)%M)%M;
}

ll second(int n){
    if(n<=2)return 0LL;
    return (nCr(n-2,n/2,M)%M + first(n-2)%M)%M;
}