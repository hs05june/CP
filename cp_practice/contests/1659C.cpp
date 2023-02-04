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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n,a,b;
        cin >> n >> a >> b;

        deq loc;
        loc.pb(0);

        int preffix[n+1] = {0};
        ll sum = 0;

        rep(i,1,n){
            int x;
            cin >> x;
            loc.pb(x);
            sum += x;
            preffix[i] = x + preffix[i-1];
        }

        ll ans = LLONG_MAX;
        rp(i,0,sz(loc)){
            ans = min(ans,(a+b)*loc[i]+b*(preffix[n]-preffix[i]-((n-i)*loc[i])));
        }

        cout << ans << endl;

    }

    return 0;}