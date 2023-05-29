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

deq graph[200007];
int k;
int value[200007], dp[200007], visited[200007], stk[200007];
bool cycle;

int dfs(int n, int mid){
    if(cycle)return 0;
    int ans = 1;
    stk[n] = 1;
    if(dp[n]!=-1)return dp[n];
    for(auto i : graph[n]){
        if(value[i]>mid)continue;
        if(visited[i] == 1 && stk[i]==1){cycle = true;return 0;}
        else if(visited[i]==0){
            visited[i] = 1;
            ans = max(ans,1+dfs(i,mid));
        }
        ans = max(ans, 1+dp[i]);
    }
    stk[n] = 0;
    return dp[n] = ans;
}

bool check(int mid, int n){
    cycle = false;
    rp(i,0,n+1){visited[i] = 0;dp[i] = -1;stk[i] = 0;}
    rp(i,1,n+1){
        if(value[i] > mid)continue;
        if(visited[i] == 0){
            visited[i] = 1;
            int x = dfs(i,mid);
        }
    }

    if(cycle)return true;
    rp(i,1,n+1){
        if(value[i]<=mid && dp[i]>=k)return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m >> k;
    int low = LLONG_MAX, high = 0;
    
    rp(i,1,n+1){
        cin >> value[i]; 
        high = max(high,value[i]);
        low = min(low,value[i]);
    }

    rp(i,0,m){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
    }

    while((high - low) > 1){
        int mid = (low+high)/2;
        if(check(mid,n)){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }

    if(check(low,n))cout << low << "\n";
    else if(check(high,n))cout << high << "\n";
    else cout << "-1\n";

    return 0;}