#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
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

int fact[100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    fact[0] = fact[1] = 1;
    // cin >> t;
    rp(i,2,100005)fact[i] = (i%M * fact[i-1]%M)%M;
    while(t--){

        int n,k;
        cin >> n >> k;

        int ans = 0;
        if(k>=n){
            cout << power(2,n,M) << "\n";
            continue;
        }

        rp(i,0,k+1){
            ans = (ans%M + ((fact[n]%M * modInverse(fact[i],M)%M)%M * modInverse(fact[n-i],M)%M)%M)%M;
        }

        cout << ans << "\n";

    }

    return 0;}