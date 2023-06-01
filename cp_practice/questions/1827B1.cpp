#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        deq arr(n+1,0);
        arr[0] = 0;

        rp(i,1,n+1)cin >> arr[i];

        int dp[n+1][n+1];

        rp(i,0,n+1){
            rp(j,0,n+1)dp[i][j] = 0;
        }

        rp(j,2,n+1){
            rp(i,1,n-j+2){
                int x = i + j - 1;
                if(arr[x] < arr[i])dp[i][x] = j-1;
                else dp[i][x] = dp[i+1][x] + dp[i][x-1] - dp[i+1][x-1];
            } 
        }

        int ans = 0;
        rp(i,1,n+1){
            rp(j,1,n+1)ans += dp[i][j];
        }

        cout << ans << "\n";

    }

    return 0;}