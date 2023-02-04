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

deq palindromes;

ll ulta(int n){
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
}

void findPalindromes(){
    palindromes.pb(0);
    for(int i = 1; i <= 40000; i++){
        if(i==ulta(i)){
            palindromes.pb(i);
        }
    }
}

ll dp[40007][500];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;
    findPalindromes();
    
    for(int i = 0; i <500;i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i <= 40000;i++){
        dp[i][0] = 0;
        for(int j = 1;j<=498;j++){
            if(palindromes[j]<=i){
                dp[i][j] = (dp[i][j-1]%M + dp[i-palindromes[j]][j]%M)%M;
            } 
            else{
                dp[i][j] = dp[i][j-1]%M;}
        }
    }
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][498] << "\n";
    }

    return 0;}