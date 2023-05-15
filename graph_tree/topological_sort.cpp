// You are given two numbers telling this number occurs before other one, Sort them following the that pattern
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

deq graph[207];
stack<int> ans;
int visited[207];

void dfs(int n){
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i);
        }
    }
    ans.push(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,m){
        int x,y;
        cin >> x >> y;
        graph[x].pb(y);
    }

    rp(i,0,n+1){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(i);
        }
    }

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;}