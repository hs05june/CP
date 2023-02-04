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

        int n,k;
        cin >> n >> k;

        int arr[n+1]={0};
        rep(i,1,n)cin >> arr[i];
        int pref[n+1]={0};
        pref[0] = 0;
        rep(i,1,n){
            pref[i] = arr[i]+pref[i-1];
        }

        if(n==1){
            cout << (arr[1] + (k-1)) << "\n";
            continue;
        }
        else if(n>=k){

            int ans = pref[k];

            for(int i = 0; i+k<=n;i++){
                ans = max(ans,pref[i+k]-pref[i]);
            }

            cout << (ans + (k*(k-1))/2) << "\n";
            continue;
        }
        else{
            // cout << "Bhai solve to kar\n";
            int ans = pref[n];
            int addon = (n*((2*k)-n-1))/2;
            cout << ans + addon << "\n";
        }
    }

    return 0;}