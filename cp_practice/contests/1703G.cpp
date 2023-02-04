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

        int n,k;
        cin >> n >> k;
        int a[n+1] = {0};
        int preffix_sum[n+1] = {0};

        rep(i,1,n){
            cin >> a[i];
            preffix_sum[i] = a[i] + preffix_sum[i-1];
        }
        
        long long ans = LLONG_MIN;
        rep(i,0,n){
            long long z = preffix_sum[i] - (i*k);
            int x = 2;
            for(int j = i+1;j<=n && j<=i+32; j++){
                z+=(a[j]/x);
                x*=2;
            }
            ans = max(ans,z);
        }
        cout << ans << endl;
    }

    return 0;}