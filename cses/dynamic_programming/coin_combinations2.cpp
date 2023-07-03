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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,x;
    cin >> n >> x;

    ll arr[n];
    rp(i,0,n) cin >> arr[i];
    
    ll dp[x+1];
    rp(i,0,x+1) dp[i] = 0;
    dp[0] = 1;

    rp(j,0,n){
        rp(i,1,x+1){
            if(i-arr[j]>=0)dp[i] = (dp[i]%M + dp[i-arr[j]]%M)%M;
        }
    }

    cout << dp[x] << "\n";

    return 0;}