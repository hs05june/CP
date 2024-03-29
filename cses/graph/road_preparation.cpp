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

    int n,m;
    cin >> n >> m;

    vector<pii> graph[n+1];

    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }

    int visited[n+1];
    rp(i,0,n+1)visited[i] = 0;

    ll ans = 0;
    multiset<pii> tree;
    tree.insert({0,1});

    while(!tree.empty()){
        auto itr = *(tree.begin());
        int weight = itr.f, parent = itr.s;
        tree.erase(tree.begin());
        if(visited[parent]==1)continue;
        visited[parent] = 1;
        ans += weight;
        for(auto i : graph[parent]){
            if(visited[i.f]==0){
                tree.insert({i.s,i.f});
            }
        }
    }

    bool check = true;
    rp(i,1,n+1)if(visited[i]==0)check = false;

    if(!check){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans << "\n";

    return 0;}