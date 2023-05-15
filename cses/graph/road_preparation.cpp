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

vector<pii> graph[100007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        int visited[n+1];
        rp(i,0,n+1){
            visited[i] = 0;
        }
        
        rp(i,0,m){
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].pb({b,c});
            graph[b].pb({a,c});
        }

        int ans = 0;
        visited[1] = 1;
        multiset<pii> edges;
        for(auto i : graph[1]){
            if(visited[i.f]==1)continue;
            edges.insert({i.s,i.f});
        }

        while(!edges.empty()){
            auto x = *(edges.begin());
            int node = x.s, dist = x.f;
            edges.erase(edges.begin());
            if(visited[node]==1)continue;
            visited[node] = 1;
            ans+=dist;
            for(auto i : graph[node]){
                int a = i.f, b = i.s;
                if(visited[a]==1)continue;
                edges.insert({b,a});
            }
        }

        bool check = true;

        rp(i,1,n+1){
            if(visited[i] == 0){
                check = false;
                break;
            }
        }

        if(!check){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << ans << "\n";

    }

    return 0;}