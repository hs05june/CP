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

vector<pii> ans;
int times[107], low_times[107],visited[107];
deq graph[107];

void dfs(int n, int timesr, int parent){
    times[n] = low_times[n] = timesr;
    for(auto i : graph[n]){
        if(i==parent)continue;
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i,timesr+1,n);
        }
        low_times[n] = min(low_times[n],low_times[i]);
        if(times[n]<low_times[i])ans.pb({n,i});
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

    visited[0] = 1;
    dfs(0,1,-1);

    rp(i,0,n+1){
        cout << i << " " << times[i] << " " << low_times[i] << "\n";
    }

    for(auto i : ans){
        cout << i.f << " " << i.s << "\n";
    }

    return 0;}