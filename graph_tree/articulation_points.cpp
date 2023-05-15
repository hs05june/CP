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

deq graph[107];
int times[107], low_time[107], visited[107];
set<int> ans;

void dfs(int n, int timer, int parent){
    times[n] = low_time[n] = timer;
    int child = 0;
    for(auto i : graph[n]){
        if(i==parent)continue;
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i,timer+1,n);
            low_time[n] = min(low_time[n],low_time[i]);
            if(low_time[i]>=times[n] && parent!=-1)ans.insert(n);
            child++;
        }
        if(visited[i]==1){
            low_time[n] = min(low_time[n], times[i]);
        }
    }
    if(parent==-1 && child>1){
        ans.insert(n);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,m){
        int x,y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    rp(i,0,n)visited[i] = 0;

    visited[0] = 1;
    dfs(0,1,-1);

    for(auto i : ans)cout << i << "\n";

    return 0;}