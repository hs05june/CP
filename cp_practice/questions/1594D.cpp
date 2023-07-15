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

set<int> graph[200007];
int parent[200007], Size[200007], visited[200007];
bool ans;
int imposter, total;

int Find(int n){
    if(n == parent[n]) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x == y) return;
    if(Size[x] > Size[y]) swap(x,y);
    Size[y] += Size[x];
    parent[x] = y;
}

void dfs(int n, int k){
    total += Size[n];
    if(k==1)imposter += Size[n];
    for(auto i : graph[n]){
        int z = (k+1)%2;
        if(visited[i]!=-1){
            if(visited[i] != z)ans = false;
            continue;
        }
        if(visited[i]==-1){
            visited[i] = z;
            dfs(i,z);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        ans = true;

        rp(i,0,n+1){
            graph[i].clear();
            Size[i] = 1;
            visited[i] = -1;
            parent[i] = i;
        }

        deq graph1[n+1];

        rp(i,0,m){
            int a,b;
            cin >> a >> b;
            string c;
            cin >> c;
            if(c == "imposter"){
                if(Find(a) == Find(b)) ans = false;
                graph1[a].pb(b);
            }
            else if(c == "crewmate"){
                Union(a,b);
            }
        }

        if(!ans){
            cout << "-1\n";
            continue;
        }

        rp(i,1,n+1){
            int z = Find(i);
            for(auto j : graph1[i]){
                int y = Find(j);
                graph[z].insert(y);
                graph[y].insert(z);
            }
        }

        int check = 0;

        rp(i,1,n+1){
            if(visited[i]==-1 && i == Find(i)){
                visited[i] = 1;
                imposter = 0, total = 0;
                dfs(i,1);
                check += max(imposter,total-imposter);
                total = 0, imposter = 0;
            }
        }

        if(!ans){
            cout << "-1\n";
            continue;
        }

        cout << check << "\n";

    }

    return 0;}