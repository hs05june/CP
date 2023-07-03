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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,m;
    cin >> n >> m;

    vector<pair<pii,int>> graph;
    
    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        graph.pb({{a,b},c});
    }

    ll distances[n+1], parent[n+1];
    rp(i,0,n+1){distances[i] = 0; parent[i] = 0;}

    rp(j,0,2*n){
        for(auto i : graph){
            if(distances[i.f.s] > i.s + distances[i.f.f]){
                distances[i.f.s] = distances[i.f.f] + i.s;
                parent[i.f.s] = i.f.f;
            }
        }
    }

    ll Start = -1;
    for(auto i : graph){
        if(distances[i.f.s] > i.s + distances[i.f.f]){
            distances[i.f.s] = distances[i.f.f] + i.s;
            parent[i.f.s] = i.f.f;
            Start = i.f.s;
        }
    }

    if(Start == -1){
        cout << "NO\n";
        return 0;
    }

    rp(i,0,n)Start = parent[Start];

    deq path;
    int visited[n+1];
    rp(i,1,n+1)visited[i] = 0;

    while(visited[Start] == 0){
        visited[Start] = 1;
        path.pb(Start);
        Start = parent[Start];
    }

    path.pb(Start);
    cout << "YES\n";
    reverse(all(path));
    for(auto i : path)cout << i << " ";
    cout << "\n";

    return 0;}