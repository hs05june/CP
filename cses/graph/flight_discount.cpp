#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
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

int visited[100007][2];
vector<pii> graph[100007];
ll distances[100007][2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
        // graph[b].pb({a,c});
    }

    rp(i,0,n+1){
        distances[i][0] = distances[i][1] = LLONG_MAX;
    }

    multiset<pair<int,pii>> bfs;
    distances[1][0] = distances[1][1] = 0;

    bfs.insert({0,{1,0}});

    while(!bfs.empty()){
        auto x = *(bfs.begin());
        int flag = x.s.s, dist = x.f, par = x.s.f;
        bfs.erase(bfs.begin());
        if(visited[par][flag]==1)continue;
        visited[par][flag] = 1;
        for(auto i : graph[par]){
            if(distances[i.f][flag] > (dist + i.s)){
                distances[i.f][flag] = dist + i.s;
                bfs.insert({dist + i.s,{i.f,flag}});
            }
        }
        if(flag == 0){
            for(auto i : graph[par]){
                if(distances[i.f][1] > (dist + (i.s/2))){
                    distances[i.f][1] = dist + (i.s/2);
                    bfs.insert({dist + (i.s/2),{i.f,1}});
                }
            }      
        }
    }

    cout << min(distances[n][0],distances[n][1]) << "\n";

    return 0;}