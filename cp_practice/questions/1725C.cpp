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
const ll M = 998244353;
using namespace std;

int fact[300007], fact_inv[300007];

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int nCr(int n, int r){
    return ((fact[n]%M * fact_inv[r]%M) * fact_inv[n-r]%M)%M;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    fact[0] = fact[1] = 1;
    rp(i,2,300005)fact[i] = (fact[i-1]%M * i%M)%M;
    rp(i,0,300005)fact_inv[i] = modInverse(fact[i],M);
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        deq arr(n,0);
        int sum = 0;

        rp(i,0,n){
            cin >> arr[i];
            sum += arr[i];
        }
        
        if(sum & 1){
            cout << power(m,n,M) << "\n";
            continue;
        }

        int x = sum / 2;
        int cnt = 0;
        rp(i,1,n)arr[i]+=arr[i-1];
        rp(i,0,n){
            int y = arr[i] + x;
            auto itr = lower_bound(all(arr),y);
            if(itr!=arr.end() && (*itr) == y)cnt++;
        }

        int ans = 0;

        rp(i,0,min(cnt,m)+1){
            int y = nCr(cnt,i)%M;
            ans = (ans%M + (((y%M * (fact[m]%M * fact_inv[m-i]%M)%M)%M * power(m-i,n-cnt-i,M)%M) * power(m-i-1,cnt-i,M)%M)%M)%M;
        }

        cout << ans << "\n";

    }

    return 0;}