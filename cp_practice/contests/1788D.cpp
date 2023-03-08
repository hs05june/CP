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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        int n;
        cin >> n;

        int arr[n+2];

        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }

        deq left[n+1],right[n+1];

        for(int i = 1; i<=n; i++){
            int x = arr[i];
            for(int j = i - 1; j >= 1; j--){
                left[i].pb(x-arr[j]);
            }
            for(int j = i + 1; j <= n; j++){
                right[i].pb(arr[j]-x);
            }
        }

        int ans = 0;

        for(int i = 1; i<=n; i++){
            for(int j = i+1; j <= n; j++){
                int x = abs(arr[j]-arr[i]);
                auto itr1 = upper_bound(all(left[i]),x);
                auto itr2 = lower_bound(all(right[j]),x);
                int z1 = itr1 - left[i].begin();
                int z2 = itr2 - right[j].begin();
                int l = sz(left[i]) - z1, r = sz(right[j]) - z2;
                ans = (ans%M + power(2,l+r,M)%M)%M;
            }
        }
        cout << ans << "\n";
    }

    return 0;}