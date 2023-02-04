//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define lb(a,b,c) lower_bound(a,b,c)
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL *a%mod) % mod;
        b >>= 1;}
    return ans;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n+1];
        deq correct(n+1,1);

        for(int i = 1; i <=n; i++){
            cin >> a[i];
        }
        
        for(int i = 1; i <= n; i++)correct[i] = 1;

        for(int i = 1; i <= n; i++){
            if(i-a[i]+1>=1){
                correct[i] = i-a[i]+1;
            }
        }

        ll h = 1;

        for(int i = 1; i <= n; i++){
            if(correct[i]!=h){
                h = max(correct[i],h);
                correct[i] = h;
            }
        }

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            auto z = upper_bound(all(correct),i);
            ll x = z - correct.begin() - i;
            ans += x;
        }

        cout << ans << "\n";
    }

    return 0;}