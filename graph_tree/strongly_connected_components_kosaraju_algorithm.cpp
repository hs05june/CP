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

deq graph[2][107];
stack<int> st;
int visited[107];

void dfs(int n, int ind){
    for(auto i : graph[ind][n]){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i,ind);
        }
    }
    if(ind==0)st.push(n);
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
        graph[0][x].pb(y);
        graph[1][y].pb(x);
    }
    rp(i,0,n){
        visited[i] = 1;
        dfs(i,0);
}
    rp(i,0,n)visited[i] = 0;

    int ans = 0;

    while(!st.empty()){
        int x = st.top();
        st.pop();
        if(visited[x]==0){
            ans++;
            visited[x] = 1;
            dfs(x,1);
        }
    }

    cout << ans << "\n";

    return 0;}