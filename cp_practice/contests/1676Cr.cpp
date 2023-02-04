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
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

ll dp[40007][500];

ll solve(ll n,ll i, deq & palindromes){
    if(n==0)return (1%M);
    if(n<0 || i>=498 || n<palindromes[i])return (0%M);

    if(dp[n][i]!=-1)return (dp[n][i]%M);

    ll ans = 0;

    for(int j = 0; j <= n; j+=palindromes[i]){
        if(n-j>=0){ans = (ans%M + solve(n-j,i+1,palindromes)%M )%M;}
        else{
            break;
        }
    }
    return dp[n][i] = (ans%M);
}

signed main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;
    deq palindromes;
    auto ulta = [](int n){
         deq digits;
    while(n>0){
        digits.pb(n%10);
        n/=10;
    }
    ll ans = 0,z = digits.size()-1;
    for(int i = 0; i <= z; i++){
        ans+=(digits[i]*power(10,(z-i),M));
    }
    return ans;
    };

    for(int i = 1; i <= 40000; i++){
        if(i==ulta(i)){
            palindromes.pb(i);
        }
    }
    // for(int i=0;i<40007;i++){
    //     for(int j = 0; j < 500; j++){
    //         dp[i][j]=-1;
    //     }
    // }

    memset(dp,-1,sizeof(dp));

    for(int i = 4000; i>0;i--){
        int x = solve(i,0,palindromes);
        cout << i << "\n";
    }
    while(t--){
        int n;
        cin >> n;
        // cout << solve(n,0,palindromes) << "\n";
    }

    return 0;}