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

deq graph[100007];
int visited[100007], st[100007];
stack<int> ans;
bool check;

void dfs(int n){
    st[n] = 1;
    for(auto i : graph[n]){
        if(visited[i]==1 && st[i]==1){
            check = true;
        }
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i);
        }
    }
    ans.push(n);
    st[n] = 0;
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
        graph[a].pb(b);
    }

    check = false;

    rp(i,1,n+1){
        if(visited[i]==0){
            visited[i] = 1;
            dfs(i);}
    }

    if(check){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;}