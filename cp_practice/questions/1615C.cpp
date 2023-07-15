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

        int n;
        cin >> n;

        string a,b;
        cin >> a >> b;

        if(a == b){
            cout << "0\n";
            continue;
        }

        ll match[2] = {0,0}, mismatch[2] = {0,0};

        rp(i,0,n){
            if(a[i]==b[i]){
                match[a[i]-'0']++;
            }
            else{
                mismatch[a[i]-'0']++;
            }
        }

        ll ans = LLONG_MAX;

        if(match[1]-match[0]==1)ans = min(ans,match[0]+match[1]);
        if(mismatch[1]==mismatch[0]) ans = min(ans,mismatch[0]+mismatch[1]);

        if(ans == LLONG_MAX){
            cout << "-1\n";
            continue;
        }

        cout << ans << "\n";

    }

    return 0;}