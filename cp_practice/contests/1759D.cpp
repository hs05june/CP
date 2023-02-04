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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        int x = n, y = n;

        int cnt2 = 0, cnt5 = 0;

        while(x%2==0){
            x/=2;
            cnt2++;
        }

        while(y%5==0){
            y/=5;
            cnt5++;
        }

        int need = max(cnt2,cnt5) - min(cnt2,cnt5);
        int to = 2;
        if(cnt5<cnt2)to = 5;
        int z = 1,z1 = 0;

        while(z<=m && z1<need){
            if(z*to>m)break;
            z*=to;
            z1++;
        }
        // cout << to << " " << cnt2 << " " << cnt5 << "\n";
        while(z<=m){
            if(z*10>m)break;
            z*=10;
        }

        int ans = m - (m % z);
        // cout << z << " " << ans << "\n";
        cout << n*ans << "\n";
    }

    return 0;}