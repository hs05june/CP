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

deq graph[100007],graph_rev[100007];
int visited[100007];

void dfs(int n){
    for(auto i : graph[n]){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(i);
        }
    }
}

void dfs1(int n){
    for(auto i : graph_rev[n]){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs1(i);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,m){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph_rev[b].pb(a);
    }

    visited[1] = 1;
    dfs(1);

    rp(i,1,n+1){
        if(visited[i]==0){
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    rp(i,1,n+1)visited[i] = 0;

    visited[1] = 1;
    dfs1(1);
    
    rp(i,1,n+1){
        if(visited[i]==0){
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;}