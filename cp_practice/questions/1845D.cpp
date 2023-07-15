#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
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

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n+1];

        rp(i,1,n+1)cin >> arr[i];

        int preff[n+1], suff[n+1];
        preff[0] = 0;

        int ans = 0, diff = LLONG_MIN;
        rp(i,1,n+1){
            preff[i] = preff[i-1] + arr[i];
        }

        suff[n] = preff[n];
        rep(i,n-1,0){
            suff[i] = min(suff[i+1],preff[i]);
        }

        rp(i,0,n+1){
            if(diff < preff[i] - suff[i]){
                diff = preff[i] - suff[i];
                ans = preff[i];
            }
        }

        cout << ans << "\n";
    }

    return 0;}