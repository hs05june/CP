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

deq graph[200007];
ll parent[200007][20];
ll levels[200007];

void dfs(int n){
    for(auto i : graph[n]){
        if(i == parent[n][0])continue;
        levels[i] = 1 + levels[n];
        parent[i][0] = n;
        dfs(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,q;
    cin >> n >> q;

    rp(i,1,n){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    levels[1] = 0;
    parent[1][0] = 0;
    dfs(1);

    rp(i,1,20){
        rp(j,1,n+1){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    while(q--){
        ll a,b;
        cin >> a >> b;
        ll x = a, y = b;
        ll mini = min(levels[a],levels[b]);

        ll z1 = levels[a] - mini;
        ll i = 0;
        while((1<<i)<=z1){
            if(((1<<i)&z1) != 0){
                a = parent[a][i];
            }
            ++i;
        }

        z1 = levels[b] - mini;
        i = 0;
        while((1<<i)<=z1){
            if(((1<<i)&z1) != 0){
                b = parent[b][i];
            }
            ++i;
        }
        if(a==b){
            cout << abs(levels[x]-levels[a]) + abs(levels[y]-levels[a]) << "\n";
            continue;
        }
        i = 19;
        while(i >= 0){
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
            --i;
        }
        ll lca = parent[a][0]; 
        cout << abs(levels[x]-levels[lca]) + abs(levels[y]-levels[lca]) << "\n";
    }

    return 0;}