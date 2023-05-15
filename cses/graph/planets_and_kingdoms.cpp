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

deq graph[2][100007];
stack<int> stk;
int visited[100007], ans[100007];

void dfs(int n, int index, int x){
    for(auto i : graph[index][n]){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i, index,x);
        }
    }
    if(index==0)stk.push(n);
    if(index==1)ans[n] = x;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,m){
        int a,b;
        cin >> a >> b;
        graph[0][a].pb(b);
        graph[1][b].pb(a);
    }

    rp(i,1,n+1){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i,0,-1);
        }
    }

    // vector<deq> ans;
    rp(i,0,n+1)visited[i]=0;
    int x = 0;
    while(!stk.empty()){
        int a = stk.top();
        stk.pop();
        if(visited[a]==0){
            visited[a] = 1;
            ++x;
            dfs(a,1,x);
        }
    }
    cout << x << "\n";
    rp(i,1,n+1)cout << ans[i] << " ";
    cout << "\n";

    return 0;}