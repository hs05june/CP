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
const ll M = 998244353;
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

        int n;
        cin >> n;

        string a;
        cin >> a;

        int cnt[n+1][2] = {0};
        int fix[2] = {0,0};

        rep(i,1,n){
            cnt[i][0]=cnt[i-1][0]+(a[i-1]=='0');
            cnt[i][1]=cnt[i-1][1]+(a[i-1]=='1');
        }

        int ans = 0;

        rep(i,1,n){
            int x = a[i-1] - '0';
            int total = 2*i-1;
            if((cnt[i][x]+fix[x])>=i){
                ans=(ans%M + power(2,i-fix[0]-fix[1]-1,M)%M)%M;
            }
            else{
                fix[x]+=(i - cnt[i][x]-fix[x]);
                ans=(ans%M + power(2,i-fix[0]-fix[1]-1,M)%M)%M;
            }
            // cout << i << " " << cnt[i][0] << " " << cnt[i][1] << " " << fix[0] << " " << fix[1] << " " << ans <<  "\n";
        }

        cout << ans%M <<"\n";

    }

    return 0;}