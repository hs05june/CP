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

int suff[5007][5007];
int pref[5007][5007];

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

        rep(i,1,n){
            cin >> arr[i];
        }

        for(int i = 1; i<=n; i++){
            for(int j = 0; j <= n+1; j++){
                pref[i][j] = 0;
            }
            for(int j = 1; j<=i; j++){
                pref[i][j] = pref[i][j-1] + (arr[j]>arr[i]);
            }
        }

        for(int i = 1; i<=n; i++){
            for(int j = 0; j <= n+1; j++){
                suff[i][j] = 0;
            }
            for(int j = n; j >= i+1; j--){
                suff[i][j] = suff[i][j+1] + (arr[i]>arr[j]);
            }
        }

        // int ans = 0;

        // for(int i = 1; i <= n; i++){
        //     for(int j = i+1;j<=n; j++){
        //         ans+=(pref[j][i-1]*suff[i][j+1]);
        //     }
        // }
        // cout << ans << "\n";
        rep(i,1,n){
            rep(j,1,n){
                cout << pref[i][j] << " ";
            }
            cout << "\n";
        }
        rep(i,1,n){
            rep(j,1,n){
                cout << suff[i][j] << " ";
            }
            cout << "\n";
        }

    }

    return 0;}