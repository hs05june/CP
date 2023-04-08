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

vector<pii> graph[200007], ulta[200007];
int distances[200007],seedha_rasta[200007],ulta_rasta[200007],seedha_rasta1[200007],distances1[200007];

void djikstra(int n, int src){
    multiset<pair<pii,bool>> bfs;
    bool visited[n+1][2] = {false};
    rp(i,0,n+1)visited[i][0] = visited[i][1] = false;
    distances[src] = 0;
    seedha_rasta[src] = 0;
    seedha_rasta1[src] = 0;
    ulta_rasta[src] = 0;
    bfs.insert({{0,src},false});
    // bfs.insert({{0,src},true});

    while(!(bfs.empty())){
        auto x = *(bfs.begin());
        bfs.erase(bfs.begin());
        int parent = x.f.s, dist = x.f.f;
        bool path = x.s;
        if(visited[parent][x.s]) continue;
        visited[parent][x.s] = true;
        // if(path){
        //     for(auto i : ulta[parent]){
        //         if(distances[i.f] > max(seedha_rasta[parent],i.s+ulta_rasta[parent])){
        //             distances[i.f] = max(seedha_rasta[parent],i.s+ulta_rasta[parent]);
        //             ulta_rasta[i.f] = i.s + ulta_rasta[parent];
        //             seedha_rasta[i.f] = seedha_rasta[parent];
        //             bfs.insert({{distances[i.f],i.f},true});
        //         }
        //     }
        //     continue;
        // }
        // for(auto i : graph[parent]){
        //     if((distances1[i.f] > (dist + i.s))){
        //         distances1[i.f] = i.s + dist;
        //         seedha_rasta1[i.f] = i.s + dist;
        //         bfs.insert({{distances1[i.f],i.f},false});
        //     }
        // }
        // for(auto i : ulta[parent]){
        //     // if(distances[i.f] > max(seedha_rasta1[parent],ulta_rasta[parent]+i.s)){
        //         distances[i.f] = max(seedha_rasta1[parent],ulta_rasta[parent]+i.s);
        //         ulta_rasta[i.f] = i.s + ulta_rasta[parent];
        //         seedha_rasta[i.f] = seedha_rasta1[parent];
        //         bfs.insert({{distances[i.f],i.f},true});
        //     // }
        // }
        if(path){
            for(auto i : ulta[parent]){
                if(distances[i.f] > distances[parent] + i.s){
                    distances[i.f] = distances[parent] + i.s;
                    seedha_rasta1[i.f] = seedha_rasta1[parent];
                    ulta_rasta[i.f] = distances[i.f]-seedha_rasta1[i.f];
                    bfs.insert({{distances[i.f],i.f},true});
                }
            }
            continue;
        }

        for(auto i : graph[parent]){
            if(seedha_rasta[i.f] > i.s + dist){
                seedha_rasta[i.f] = i.s + dist;
                bfs.insert({{i.s+dist,i.f},false});
            }
        }

        for(auto i : ulta[parent]){
            if((distances[i.f] > seedha_rasta[parent] + i.s) ){
                seedha_rasta1[i.f] = seedha_rasta[parent];
                ulta_rasta[i.f] = i.s;
                    distances[i.f] = seedha_rasta[parent]+i.s;
                bfs.insert({{seedha_rasta[parent]+i.s,i.f},true});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        rp(i,0,m){
            int x,y,w;
            cin >> x >> y >> w;
            graph[x].pb({y,w});
            ulta[y].pb({x,w});
        }

        rp(i,0,n+1){
            distances[i] = LLONG_MAX;
            seedha_rasta[i] = LLONG_MAX;
            seedha_rasta1[i] = LLONG_MAX;
            ulta_rasta[i] = LLONG_MAX;
        }

        djikstra(n,1);

        // rp(i,0,n+1)cout << distances[i] << " ";
        // cout << "\n";
        // rp(i,0,n+1)cout << seedha_rasta[i] << " ";
        // cout << "\n";
        // rp(i,0,n+1)cout << seedha_rasta1[i] << " ";
        // cout << "\n";
        // rp(i,0,n+1)cout << ulta_rasta[i] << " ";
        // cout << "\n";

        rp(i,2,n+1){
            int x = min(distances[i],seedha_rasta[i]);
            if(x==LLONG_MAX)cout << "-1 ";
            else cout << x << " ";
        }

    }

    return 0;}