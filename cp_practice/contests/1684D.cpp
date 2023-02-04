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

int solve(int arr[], int n, int index, int k, int z){
    if(index>n || (k>n-index))return 0;
    
    int ans = z+arr[index] + solve(arr,n,index+1,k,z);
    
    if(arr[index]>n+1-k-index && k>0){
        ans = min(ans,solve(arr,n,index+1,k-1,z+1));
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        int arr[n+1] = {0};

        set<pii> to_remove;

        rep(i,1,n){
            cin >> arr[i];
            to_remove.insert({arr[i]-(n-i),i});
        }

        deq hatto;
        int x = 0;

        while(x<k){
            pii z = *(--to_remove.end());
            to_remove.erase((--to_remove.end()));
            hatto.pb(z.s);
            x++;
        }

        sort(all(hatto));
        int z = 0,ans = 0, index = 0;
        
        rep(i,1,n){
            if(index<sz(hatto) && hatto[index]==i){
                index++;
                z++;
                continue;
            }
            ans+=(z+arr[i]);
        }

        cout << ans << "\n";

        // cout << solve(arr,n,1,k,0) << "\n";

    }

    return 0;}