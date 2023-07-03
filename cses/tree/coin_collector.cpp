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

ll values[100007];
ll values1[100007];
ll scc[100007];
deq graph[100007];
deq graph2[100007];
set<int> graph1[100007];
ll visited[100007];
ll dp[100007];
ll t;
stack<ll> st;

void dfs(int n){
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i);
        }
    }
    st.push(n);
}

void dfs2(int n){
    for(auto i : graph2[n]){
        if(visited[i]==0){
            visited[i]=1;
            dfs2(i);
        }
    }
    scc[n]=t;
}

ll solve(int n){
    if(dp[n] != -1)return dp[n];
    ll ans = 0;
    for(auto i : graph1[n]){
        ans = max(ans,solve(i));
    }
    return dp[n] = (values1[n]+ans);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,m;
    cin >> n >> m;

    rp(i,1,n+1)cin >> values[i];

    rp(i,0,m){
        ll a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph2[b].pb(a);
    }

    rp(i,1,n+1){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i);
        }
    }

    rp(i,0,n+1)visited[i] = 0;

    while(!st.empty()){
        ll x = st.top();
        if(visited[x]==0){
            visited[x] = 1;
            ++t;
            dfs2(x);
        }
        st.pop();
    }

    rp(i,1,n+1){
        int x = scc[i];
        values1[x] += values[i];
        for(auto j : graph[i]){
            if(x != scc[j])graph1[x].insert(scc[j]);
        }
    }

    ll ans = 0;

    rp(i,1,t+1)dp[i] = -1;
    
    rp(i,1,t+1){
        ans = max(ans,solve(i));
    }

    cout << ans << "\n";

    return 0;}