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

    int n,m;
    cin >> n >> m;

    ll ans = 0;
    int a[n];

    rp(i,0,n){
        cin >> a[i];
        ans += ((i+1)*(n-i));
    }

    rp(i,1,n){
        if(a[i]==a[i-1]){
            ans -= (i*(n-i));
        }
    }

    while(m--){
        int x,y;
        cin >> x >> y;
        int z = x - 1;
        if(y==a[z]){
            cout << ans << "\n";
            continue;
        }
        if((z-1)>=0){
            if(a[z-1]==a[z] && a[z-1]!=y){
                ans += (z*(n-z));
            }
            else if(a[z-1]!=a[z] && a[z-1]==y){
                ans -= (z*(n-z));
            }
        }

        if((z+1)<n){
            if(a[z+1]==a[z] && a[z+1]!=y){
                ans += ((z+1)*(n-z-1));
            }
            else if(a[z+1]!=a[z] && a[z+1]==y){
                ans -= ((z+1)*(n-z-1));
            }
        }
        a[z] = y;
        cout << ans << "\n";
    }

    return 0;}