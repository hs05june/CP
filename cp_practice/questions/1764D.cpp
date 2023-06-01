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
ll M = 1000000007;
using namespace std;

int fact[5007], fact_inv[5007];

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int nCr(int n, int r, int M){
    return ((fact[n]%M * fact_inv[r])%M * fact_inv[n-r]%M)%M;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n >> M;

    fact[0] = fact[1] = 1;

    rp(i,2,5007)fact[i] = (i%M * fact[i-1]%M)%M;
    rp(i,0,5007)fact_inv[i] = modInverse(fact[i],M)%M;

    if((n%2) == 0){
        int x = n/2;
        int y = n - x;
        int ans = 0;
        rp(i,2,y+1){
            int z = 0;
            rp(j,i,y+1){
                int x1 = j - 2;
                int y1 = i - 2;
                int z1 = j;
                int left = n - i - 1;
                z = (z%M + ((nCr(x1,y1,M)%M * z1%M)%M * fact[left]%M)%M)%M;
            }
            ans = (ans%M + (n%M * z%M)%M)%M;
        }
        ans = (ans%M + (n%M * fact[n-2]%M)%M)%M;
        cout << ans << "\n";
    }
    else{
        int x = n/2;
        int y = n - x;
        int ans = 0;
        rp(i,2,y+1){
            int z = 0;
            rp(j,i,y+1){
                int x1 = j - 2;
                int y1 = i - 2;
                int z1 = j - 1;
                int left = n - i - 1;
                z = (z%M + ((nCr(x1,y1,M)%M * z1%M)%M * fact[left]%M)%M)%M;
            }
            ans = (ans%M + (n%M * z%M)%M)%M;
        }
        cout << ans << "\n";
    }

    return 0;}