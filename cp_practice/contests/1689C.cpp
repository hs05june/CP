#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

vector<int> graph[300007];
int child[300007],depth[300007],maxi[300007];
int visited[300007],done[300007],dp[300007];

void dfs(int n, int parent){
    depth[n] = 1 + depth[parent];
    bool check = true;

    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i]=1;
            check = false;
            dfs(i,n);
            child[n]+=(child[i]);
            maxi[n] = max(maxi[n],maxi[i]);
            }
    }
    if(check){
        maxi[n] = depth[n];
        child[n] = 1;
        return;
    }
    child[n]++;

}

int solve(int n){
    bool check = true;

    for(auto i : graph[n]){
        if(done[i]==0){
            check = false;
        }
    }

    if(graph[n].size()==0 || check)return 0;

    if(dp[n]!=-1)return dp[n];

    if(graph[n].size()==1){
        int x = graph[n][0];
        done[x] = 1;
        // cout << x << "\n";
        return dp[n] = (child[x]-1);
    }

    if(graph[n].size()==2 && (done[graph[n][0]]==1 || done[graph[n][1]]==1)){
        int x = done[graph[n][0]] == 0 ? graph[n][0] : graph[n][1];
        done[x] = 1;
        return dp[n] = (child[x]-1);
    }

    int x[2];int j = 0;

    for(auto i : graph[n]){
        if(done[i]==0){
            x[j] = i;
            done[i] = 1;
            ++j;
        }
    }

    // return dp[n] = max((child[x[1]]-1)+solve(x[0]),(child[x[0]]-1)+solve(x[1]));
    int ans = LLONG_MIN;
    done[x[0]] = 1;
    ans = max((child[x[1]]-1)+solve(x[0]),ans);
    done[x[0]] = 0;
    done[x[1]] = 1;
    ans = max((child[x[0]]-1)+solve(x[1]),ans);
    done[x[1]] = 0;
    return dp[n]=ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        rep(i,1,n){
            graph[i].clear();
            child[i] = 0;
            visited[i] = 0;
            done[i] = 0;
            maxi[i] = 0;
            depth[i] = 0;
            dp[i] = -1;
        }

        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);    
        }

        visited[1] = 1;
        dfs(1,0);
        done[1] = 1;

        // rep(i,1,n){
        //     cout << child[i] << " " << depth[i] << " " << maxi[i] << "\n";
        // }
        cout << solve(1) << "\n";
    }

    return 0;}