// Used to find Minimum Spanning Tree
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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;
    vector<pii> graph[n];

    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }

    int visited[n];
    int parent[n];
    rp(i,0,n){visited[i] = 0;parent[i] = -1;}
    multiset<pair<int,pii>> mst; // {weight, {node,parent}}
    mst.insert({0,{0,-1}});

    while(!mst.empty()){
        auto x = *(mst.begin());
        mst.erase(mst.begin());
        int weight = x.f, node = x.s.f, par = x.s.s;
        if(visited[node]==1)continue;
        visited[node] = 1;
        parent[node] = par;
        cout << par << " " << node << " " << weight << "\n";
        for(auto i : graph[node]){
            if(visited[i.f]==0){
                mst.insert({i.s,{i.f,node}});
            }
        }
    }

    return 0;}