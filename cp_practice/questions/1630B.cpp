#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
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

        int n,k;
        cin >> n >> k;

        int arr[n];
        deq array;

        rp(i,0,n){
            cin >> arr[i];
            array.pb(arr[i]);
        }

        sort(all(array));
        int z = ceil(((ld)n + (ld)k) / (ld)2);

        int diff = INT_MAX;
        pii seg = {-1,-1};

        rp(i,0,n - z + 1){
            if(diff > abs(array[i+z-1] - array[i])){
                diff = abs(array[i+z-1] - array[i]);
                seg = {array[i],array[i+z-1]};
            }
        }

        vector<pii> ans;

        int preff[n+1];
        preff[0] = 0;
        rp(i,1,n+1){
            preff[i] = (arr[i-1] >= seg.f && arr[i-1] <= seg.s) ? 1+preff[i-1] : -1+preff[i-1];
        }

        int prev = 0;

        rp(i,1,n+1){
            int x = i;
            while(i <= n && (preff[i] - preff[x-1]) <= prev){
                ++i;
            }
            ans.pb({x,i});
        }

        while(sz(ans) > k){
            ans.pop_back();
        }

        ans[k-1].s = n;

        cout << seg.f << " " << seg.s << "\n";
        for(auto i : ans)cout << i.f << " " << i.s << "\n";

    }

    return 0;}