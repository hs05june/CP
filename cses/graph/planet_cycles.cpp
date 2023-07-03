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

int arr[200007], parent[200007];
int dp[200007], levels[200007];
set<int> dfs;

void solve(int n){
    if(dfs.count(n)){
        int z = abs(levels[n]-levels[parent[n]]) + 1;
        dp[n] = z;
        int par = parent[n];
        while(par != n){
            dp[par] = z;
            par = par[parent];
        }
        return;
    }
    dfs.insert(n);
    levels[n] = 1+levels[parent[n]];
    if(dp[arr[n]]==-1){
        parent[arr[n]] = n;
        solve(arr[n]);
    }
    if(dp[n]==-1)dp[n] = 1 + dp[arr[n]];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i,0,n+1)dp[i] = -1;

    rp(i,1,n+1) cin >> arr[i];

    rp(i,1,n+1){
        dfs.clear();
        if(dp[i]==-1){
            solve(i);
        }
    }

    rp(i,1,n+1)cout << dp[i] << " ";

    return 0;}