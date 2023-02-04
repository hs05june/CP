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

        int n;
        cin >> n;

        int a[n],b[n];

        rp(i,0,n)cin >> a[i];
        rp(i,0,n)cin >> b[i];
        // Two Wire
        int ans = abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]);
        ans = min(ans,abs(a[0]-b[n-1]) + abs(a[n-1]-b[0]));

        // Four Wire
        int x[4];
        rp(i,0,4)x[i] = LLONG_MAX;

        rp(i,0,n){
            x[0] = min(x[0],abs(a[0]-b[i]));
            x[1] = min(x[1],abs(a[n-1]-b[i]));
            x[2] = min(x[2],abs(a[i]-b[0]));
            x[3] = min(x[3],abs(a[i]-b[n-1]));
        }

        ans = min(ans,x[0]+x[1]+x[2]+x[3]);

        int y[2];
        rp(i,0,2)y[i] = LLONG_MAX;
        rp(i,0,n){
            y[0] = min(y[0],abs(a[i]-b[n-1]));
            y[1] = min(y[1],abs(b[i]-a[n-1]));
        }
        ans = min(ans,abs(a[0]-b[0])+y[0]+y[1]);
        rp(i,0,2)y[i] = LLONG_MAX;
        rp(i,0,n){
            y[0] = min(y[0],abs(a[i]-b[0]));
            y[1] = min(y[1],abs(b[i]-a[0]));
        }
        ans = min(ans,abs(a[n-1]-b[n-1])+y[0]+y[1]);
        rp(i,0,2)y[i] = LLONG_MAX;
        rp(i,0,n){
            y[0] = min(y[0],abs(a[i]-b[0]));
            y[1] = min(y[1],abs(b[i]-a[n-1]));
        }
        ans = min(ans,abs(a[0]-b[n-1])+y[0]+y[1]);
        rp(i,0,2)y[i] = LLONG_MAX;
        rp(i,0,n){
            y[0] = min(y[0],abs(a[i]-b[n-1]));
            y[1] = min(y[1],abs(b[i]-a[0]));
        }
        ans = min(ans,abs(a[n-1]-b[0])+y[0]+y[1]);

        cout << ans << "\n";

    }

    return 0;}