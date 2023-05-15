// Topological Sort Using BFS ke liye Algorithm
// This can be used to detect cycle in directed graph, Since, then the length of topological sort will not be equal to the number of vertex
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

deq graph[207];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    int indegree[n+1];
    rp(i,0,n+1)indegree[i] = 0;

    rp(i,0,m){
        int x,y;
        cin >> x >> y;
        graph[x].pb(y);
        indegree[y]++;
    }

    queue<int> bfs;
    int visited[n+1];
    rp(i,0,n+1)visited[i] = 0;

    rp(i,0,n+1)if(indegree[i]==0)bfs.push(i);

    deq topo;

    while(!bfs.empty()){
        int x = bfs.front();
        bfs.pop();
        if(visited[x]==1)continue;
        visited[x] = 1;
        for(auto i : graph[x]){
            indegree[i]--;
            if(indegree[i]==0){
                bfs.push(i);
            }
        }
        topo.pb(x);
    }

    if(topo.size()!=n){
        cout << "Topological Sort not possible\n";
    }

    for(auto i : topo){
        cout << i << " ";
    }

    return 0;}