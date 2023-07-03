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
    // cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        int arr[n];
        multiset<int> ele;
        rp(i,0,n){cin >> arr[i];ele.insert(arr[i]);}

        int ans = LLONG_MAX;
        deq mi;

        for(auto i : ele){
            if(sz(mi) >= 2)break;
            mi.pb(i);
        }
        
        ans = min(ans, (int)(ceil((ld)mi[0] / (ld)2) + ceil((ld)mi[1] / (ld)2)));

        rp(i,0,n-1){
            int maxi = max(arr[i],arr[i+1]);
            int mini = min(arr[i],arr[i+1]);
            if(maxi >= 2*mini){
                ans = min(ans, (int)(ceil((ld)maxi / (ld)2)));
            }
            else{
                ans = min(ans, (int)(ceil(((ld)maxi + (ld)mini)/(ld)3)));
            }
        }

        rp(i,0,n-2){
            int maxi = max(arr[i],arr[i+2]);
            int mini = min(arr[i],arr[i+2]);
            ans = min(ans, (int)(ceil((ld)(maxi-mini)/(ld)2)) + mini);
        }

        cout << ans << "\n";

    }

    return 0;}