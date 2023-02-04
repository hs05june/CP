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

        int n,x;
        cin >> n >> x;

        int arr[n];
        
        int mini = LLONG_MAX, maxi = LLONG_MIN;

        mii cnt;

        rp(i,0,n){
            cin >> arr[i];
            cnt[arr[i]]++;
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]);
        }

        int ans = 0;
        rp(i,1,n){
            ans+=abs(arr[i]-arr[i-1]);
        }
        // cout << ans << "\n";
        if(maxi < x){
            // if(arr[n-1]==maxi || arr[0]==maxi){
            //     ans+=abs(maxi-x);
            // }            
            // else{
            //     ans+=2*(abs(maxi-x));
            // }
            int to_add = LLONG_MAX;
            to_add = min(to_add,abs(arr[n-1]-x));
            to_add = min(to_add,abs(arr[0]-x));
            to_add = min(to_add,2*abs(maxi-x));
            ans+=to_add;
        }

        // cout << ans << "\n";

        if(mini > 1){
            int to_add = LLONG_MAX;
            to_add = min(to_add,abs(arr[n-1]-1));
            to_add = min(to_add,abs(arr[0]-1));
            to_add = min(to_add,2*abs(mini-1));
            ans+=to_add;
            // if(arr[0]==mini || arr[n-1]==mini){
            //     ans+=abs(mini-1);
            // }
            // else{
            //     ans+=2*(abs(mini-1));
            // }
        }

        cout << ans << "\n";
    }

    return 0;}