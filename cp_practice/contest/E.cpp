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

        ll n;
        cin >> n;

        mii cnt;
        ll m = n;

        deq ans;

        rp(i,0,n){
            ll a;
            cin >> a;
            cnt[a]++;
        }

        int maxi = cnt[0];

        rp(i,0,n+1){
            if(maxi == 0){
                break;
            }
            if(cnt[i] < maxi){
                int z = maxi - cnt[i];
                m -= z * i;
                rp(j,0,z)ans.pb(i);
                maxi = cnt[i];
            }
        }

        rp(i,0,m)ans.pb(0);

        sort(all(ans));
        reverse(all(ans));
        cout << sz(ans) << "\n";
        for(auto i : ans)cout << i << " ";
        cout << "\n";

    }

    return 0;}