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

        ll n, k;
        cin >> n >> k;

        ll arr[n];
        rp(i,0,n)cin >> arr[i];

        set<ll> cant;
        deq tosort;

        rp(i,0,n){
            if(abs(i-0) >= k || abs(n-1-i)>=k){
                tosort.pb(arr[i]);
            }
            else cant.insert(i);
        }
        sort(all(tosort));
        int j = 0;

        rp(i,0,n){
            if(!cant.count(i)){
                arr[i] = tosort[j];
                ++j;
            }
        }

        rp(i,0,n)cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;}