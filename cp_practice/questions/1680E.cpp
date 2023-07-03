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

        char arr[2][n+1];

        rp(j,0,2){
            rp(i,1,n+1)cin >> arr[j][i];
        }

        int preffix[n+2];
        preffix[0] = 0;
        preffix[n+1] = 0;
        rp(i,1,n+1)preffix[i] = (preffix[i-1] + ((arr[0][i]=='*') + (arr[1][i]=='*')));
        int dp1[2][n+2], dp2[2][n+2];
        dp1[0][0] = dp1[1][0] = dp2[0][0] = dp2[1][0] = 0;
        dp1[0][n+1] = dp1[1][n+1] = dp2[0][n+1] = dp2[1][n+1] = 0;
        rp(i,1,n+1){
            int x = (dp1[0][i-1] + (preffix[i-1] != 0));
            int y = (dp1[1][i-1] + (preffix[i-1] != 0));
            dp1[0][i] = min(x + (arr[1][i]=='*'), y + 1);
            dp1[1][i] = min(x + 1, y + (arr[0][i]=='*'));
        }

        rep(i,n,1){
            int x = (dp2[0][i+1] + (preffix[n] - preffix[i] != 0));
            int y = (dp2[1][i+1] + (preffix[n] - preffix[i] != 0));
            dp2[0][i] = min(x + (arr[1][i]=='*'), y + 1);
            dp2[1][i] = min(x + 1, y + (arr[0][i]=='*'));
        }

        int ans = LLONG_MAX;
        rp(i,1,n+1){
            ans = min(ans,dp1[0][i] + dp2[0][i+1] + (preffix[n] - preffix[i] != 0));
            ans = min(ans,dp1[1][i] + dp2[1][i+1] + (preffix[n] - preffix[i] != 0));
        }
        cout << ans << '\n';
    }

    return 0;}