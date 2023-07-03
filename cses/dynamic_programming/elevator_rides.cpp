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

pii dp[((1LL)<<20)];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n, x;
    cin >> n >> x;

    int arr[n];
    rp(i,0,n) cin >> arr[i];

    dp[0] = {0LL,0LL};

    rp(i,1,(1<<n)){
        dp[i] = {INT_MAX,INT_MAX};
        rp(j,0,n){
            if((i & (1<<j)) != 0){
                int y = (i ^ (1<<j));
                if(dp[y].s + arr[j] <= x){
                    dp[i] = min(dp[i],{dp[y].f,dp[y].s+arr[j]});
                }
                else{
                    dp[i] = min(dp[i],{1+dp[y].f,arr[j]});
                }
            }
        }
    }

    ll ans = dp[(1<<n)-1].f;
    if(dp[(1<<n)-1].s != 0)ans ++;
    cout << ans << "\n";

    return 0;}