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

int n,l,k;
int dp[505][505],d[505],a[505];

int solve(int index, int left){
    if(index>n+1)return 0;

    if(dp[index][left]!=-1){
        return dp[index][left];
    }

    int ans = LLONG_MAX;
    
    for(int i = 1; i<=(n+1-index);i++){
        if(i-1>left)break;
        ans = min(ans,a[index]*(d[index+i]-d[index])+solve(index+i,left-i+1));
    }

    return dp[index][left]=ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while(t--){

        cin >> n >> l >> k;

        rp(i,1,n+1)cin >> d[i];
        rp(i,1,n+1)cin >> a[i];

        d[n+1] = l;

        rp(i,0,n+1){
            rp(j,0,k+1){
                dp[i][j] = -1;
            }
        }

        cout << solve(1,k) << "\n";

    }

    return 0;}