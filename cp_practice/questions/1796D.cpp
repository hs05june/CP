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
const ll M = 100000000000007;
using namespace std;

int dp[200007][25][3];
int arr[200007];

int solve(int ind, int k, int flag, int n, int x){
    if(ind > n){
        if(k==0)return 0;
        else return -M;
    }
    if(dp[ind][k][flag] != LLONG_MIN)return dp[ind][k][flag];
    int ans = LLONG_MIN;
    if(flag==0){
        ans = max(ans,solve(ind+1,k,0,n,x));
        if(k>0)ans = max(ans, solve(ind+1,k-1,0,n,x));
        if(k>0)ans = max(ans, solve(ind+1,k-1,1,n,x));
        ans = max(ans, solve(ind+1,k,1,n,x));
    }
    else if(flag == 1){
        ans = max(ans,arr[ind] - x + solve(ind+1,k,1,n,x));
        if(k>0)ans = max(ans,arr[ind] + x + solve(ind+1,k-1,1,n,x));
        if(k>0)ans = max(ans, arr[ind] + x + solve(ind+1,k-1,2,n,x));
        ans = max(ans, arr[ind] - x + solve(ind+1,k,2,n,x));
    }
    else if(flag == 2){
        ans = max(ans,solve(ind+1,k,2,n,x));
        if(k>0)ans = max(ans,solve(ind+1,k-1,2,n,x));
    }
    return dp[ind][k][flag] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,k,x;
        cin >> n >> k >> x;

        rp(i,0,n+1){
            rp(j,0,k+1){
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = LLONG_MIN;
            }
        }

        rp(i,1,n+1)cin >> arr[i];

        cout << max(max(solve(1,k,0,n,x),solve(1,k,1,n,x)),solve(1,k,2,n,x)) << "\n";

    }

    return 0;}