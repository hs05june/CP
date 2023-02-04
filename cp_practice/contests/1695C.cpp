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

int dp[1007][1007][2];

// 0 -> min, 1 -> max

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        rep(i,0,n){
            rep(j,0,m){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }

        int a[n+1][m+1] = {0};

        rep(i,1,n){
            rep(j,1,m){
                cin >> a[i][j];
            }
        }
        if((n+m)%2==0){
            cout << "NO\n";
            continue;
        }
        dp[1][1][0] = a[1][1];
        dp[1][1][1] = a[1][1];
        rep(i,2,n){
            dp[i][1][0] = a[i][1] + dp[i-1][1][0];
            dp[i][1][1] = a[i][1] + dp[i-1][1][1];
        }
        rep(j,2,m){
            dp[1][j][0] = a[1][j] + dp[1][j-1][0];
            dp[1][j][1] = a[1][j] + dp[1][j-1][1];
        }
        rep(i,2,n){
            rep(j,2,m){
                dp[i][j][0] = a[i][j]+min(dp[i-1][j][0],dp[i][j-1][0]);
                dp[i][j][1] = a[i][j]+max(dp[i-1][j][1],dp[i][j-1][1]);
            }
        }
        dp[n][m][0]<=0 && dp[n][m][1]>=0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}