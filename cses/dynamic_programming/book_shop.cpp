#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll int
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

ll dp[1007][100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,x;
    cin >> n >> x;

    ll price[n+1] = {0}, pages[n+1]={0};

    rp(i,1,n+1)cin >> price[i];
    rp(i,1,n+1)cin >> pages[i];

    rp(i,0,n+1){
        rp(j,0,x+1) dp[i][j] = 0;
    }

    rp(i,1,n+1){
        rp(j,1,x+1){
            dp[i][j] = dp[i-1][j];
            if(j-price[i] >= 0){
                dp[i][j] = max(dp[i][j], pages[i] + dp[i-1][j-price[i]]);
            }
        }
    }

    cout << dp[n][x] << "\n";

    return 0;}