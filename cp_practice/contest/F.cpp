#include<bits/stdc++.h>
#define sz 200005
#define mod 1000000007
#define l 20
#define ll long long int
using namespace std;
int n,lev[sz],up[sz + 10][l + 10],tin[sz + 10],tout[sz + 10],tim; 
vector<int>adj[sz + 10];
void dfs(int v, int p) {
    up[v][0] = p;
    lev[v] = lev[p] + 1;
    tin[v] = ++tim;
    for(int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = tim;
    return;
}
bool is_ancestor(int u,int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    if(lev[u]<lev[v])
        swap(u,v);
    for(int i = l;i >= 0; i--)
        if(lev[up[u][i]] >= lev[v])
            u = up[u][i];
    for(int i = l;i >= 0; i--)
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    if(u != v) {
        u = up[u][0];
        v = up[v][0];
    }
    return u;
}
int dis(int a, int b) {
    int lc = lca(a, b);
    return lev[a] - lev[lc] + lev[b] - lev[lc];
}
pair<int,int> kor(pair<int,int>a1, int b1) {
    int ager = dis(a1.first, a1.second);
    int a10 = dis(a1.first, b1);
    int a11 = dis(a1.second, b1);
    if(ager >= max(a11, a10)) return a1;
    if(a10 >= max(ager, a11)) return {a1.first, b1};
    return {a1.second, b1};
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        tim = 0;
        int n, q; cin >> n >> q;
        for(int i = 2; i <= n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a); 
        } dfs(1, 0);
        while(q--) {
            int a; cin >> a;
            vector<int>v(a);
            for(int &u:v) cin >> u;
            std::vector<int> v1;
            int ans = 0;
            if(a == 1) {
                cout << "0\n";
                continue;
            } pair<int,int>dia = {v[0], v[1]};
            for(int i = 2; i < a; i++) {
                dia = kor(dia, v[i]);
            } cout << (dis(dia.first, dia.second) + 1) / 2 << "\n";
        } for(int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
}