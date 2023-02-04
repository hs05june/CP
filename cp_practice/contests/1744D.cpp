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

        int n;
        cin >> n;

        int a[n+1] = {0};

        int ans = 0;

        rep(i,1,n){
            cin >> a[i];
            int x = a[i];
            while(x%2==0){
                ans++;
                x/=2;
            }
        }

        int x = 0,z = 2;

        while(z<=n){
            z*=2;
            ++x;
        }
        deq power_of_2;
        int sum = 0;
        while(z>1){
            power_of_2.pb(((n/z)-sum));
            sum+=((n/z)-sum);
            z/=2;
        }
        int ans1 = 0;        
        // cout << x;
        rp(i,1,sz(power_of_2)){
            if(ans>=n)break;
            if((x*power_of_2[i])<=(n-ans)){
                ans1+=power_of_2[i];
                ans+=(x*power_of_2[i]);
            }
            else{
                int k = (n-ans)%x==0 ? (n-ans)/x : (n-ans)/x + 1;
                ans+=(x*k);
                ans1+=k;
            }
            --x;
        }

        ans >= n ? cout << ans1 << "\n" : cout << "-1\n";

    }

    return 0;}