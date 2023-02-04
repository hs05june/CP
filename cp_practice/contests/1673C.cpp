#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
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

vector<int> palindromes;

int dp[507][40007];

int rev(int n){
    int ans = 0;
    while(n!=0){
        ans*=10;
        ans+=(n%10);
        n/=10;
    }
    return ans;
}

void Make(){
    rep(i,1,40007){
        if(i==rev(i)){
            palindromes.pb(i);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    Make();

    rep(i,0,500){
        dp[i][0] = 1;
    }

    rep(i,1,499){
        rep(j,1,40000){
            dp[i][j] = dp[i-1][j]%M;
            if(j-palindromes[i-1]>=0){
                dp[i][j] = (dp[i-1][j]%M + dp[i][j-palindromes[i-1]]%M)%M;
            }
        }
    }

    while(t--){

        int n;
        cin >> n;
        cout << dp[499][n] << "\n";     
        
    }
    return 0;}
