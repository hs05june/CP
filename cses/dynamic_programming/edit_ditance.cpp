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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string a,b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int dp[n+1][m+1];

    rp(i,0,n+1)dp[i][0] = i;
    rp(i,0,m+1)dp[0][i] = i;
    dp[0][0] = 0;

    rp(i,1,n+1){
        rp(j,1,m+1){
            dp[i][j] = INT_MAX;
            dp[i][j] = min(dp[i][j], (a[i-1] != b[j-1]) + dp[i-1][j-1]);
            dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
            dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";

    return 0;}