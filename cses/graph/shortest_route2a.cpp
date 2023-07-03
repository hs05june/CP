#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

ll levels[507][507];
vector<pii> graph[507];
int done[507];

void djikstra(int src, int n){
    levels[src][src] = 0;
    int visited[n+1];
    rp(i,0,n+1){
        visited[i] = 0;
    }

    multiset<pii> bfs;
    bfs.insert({0,src});
    while(!bfs.empty()){
        auto itr = *(bfs.begin());
        ll parent = itr.s, dist = itr.f;
        bfs.erase(bfs.begin());        
        if(visited[parent]==1)continue;
        visited[parent] = 1;
        for(auto i : graph[parent]){
            ll child = i.f, weight = i.s;
            if(weight + dist < levels[src][child]){
                levels[src][child] = weight + dist;
                bfs.insert({weight + dist,child});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m,q;
    cin >> n >> m >> q;

    rp(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }

    rp(i,0,n+1){
        rp(j,0,n+1){
            levels[i][j] = LLONG_MAX;
        }
    }

    while(q--){
        ll a,b;
        cin >> a >> b;
        if(done[a] == 1){
            (levels[a][b] == LLONG_MAX) ? cout << "-1\n" : cout << levels[a][b] << "\n";
        }
        else if(done[b]==1){
            (levels[b][a] == LLONG_MAX) ? cout << "-1\n" : cout << levels[b][a] << "\n";
        }
        else{
            djikstra(a,n);
            done[a] = 1;
            (levels[a][b] == LLONG_MAX) ? cout << "-1\n" : cout << levels[a][b] << "\n";
        }
    }

    return 0;}