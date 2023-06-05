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

deq graph[200007];
int parent[200007], depth[200007], visited[200007];
int euler[400007],first[2000007];
pii sparse[400007][30];
int tim;
void dfs(int n){
    first[n] = tim;
    euler[tim] = n;
    ++tim;
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            parent[i] = n;
            depth[i] = 1 + depth[n];
            dfs(i);
        }
    }
    euler[tim] = parent[n];
    ++tim;
}

int lca(int x, int y){
    int a = first[x], b = first[y];
     if(first[x] > first[y])swap(x,y);
    int siz = first[y] - first[x] + 1;
    pii ans = {INT_MAX,0};
    int anc = first[x];
    int i = 0;
    while(siz >= (1<<i)){
        if((siz & (1<<i))!=0){
            ans = min(ans,sparse[anc][i]);
            anc+=((1<<i));
        }
        ++i;
    }
    return ans.s;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    rp(i,1,n){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    visited[1] = 1;
    depth[1] = 0;
    parent[1] = 0;
    tim = 1;
    dfs(1);

    int maxi = 0;
    rp(i,1,n+1)maxi = max(first[i],maxi);

    rp(i,1,maxi+1){
        sparse[i][0] = {depth[euler[i]],euler[i]};
    }

    for(int j = 1; (1<<j)<=maxi;j++){
    rp(i,1,maxi+1){
        int k = j-1;
        if(i+(1<<k) <= maxi+10)sparse[i][j] = min(sparse[i][k],sparse[i+((1LL)<<k)][k]);
        else break;
        }
    }

    int m;
    cin >> m;

    while(m--){
        int k;
        cin >> k;
        set<pii> element;

        rp(i,0,k){
            int x;
            cin >> x;
            visited[x] = 0;
            element.insert({-depth[x],x});
        }        
        if(k<=2){
            cout << "YES\n";
            continue;
        }

        int ancestor = (*element.begin()).s;
        visited[(*element.begin()).s] = 1;
        for(auto i : element){
            int x = lca(ancestor,i.s);
            if(x == i.s){
                ancestor = x;
                visited[i.s] = 1;
            }
        }
        int ancestor1 = 0;
        for(auto i : element){
            if(visited[i.s]==0){
                if(ancestor1 == 0){
                    int x = lca(i.s, (*(element.begin())).s);
                    int y = lca(ancestor,x);
                    if(y!=x)break;
                    ancestor1 = i.s;
                    visited[i.s] = 1;
                }
                else{
                    int x = lca(ancestor1,i.s);
                    if(x == i.s){
                        visited[i.s] = 1;
                        ancestor1 = x;
                    }
                }
            }
        }
        bool ans = true;
        for(auto i : element){
            if(visited[i.s]==0)ans = false;
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}