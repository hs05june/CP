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
int levels[200007][3];
int visited[200007][3];

void dfs(int n, int index){
    for(auto i : graph[n]){
        if(visited[i][index]==0){
            visited[i][index] = 1;
            levels[i][index] = 1 + levels[n][index];
            dfs(i,index);
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

        int n,k,c;
        cin >> n >> k >> c;

        rp(i,0,n+1){
            graph[i].clear();
            visited[i][0] = visited[i][1] = visited[i][2] = 0;
            levels[i][0] = levels[i][1] = levels[i][2] = 0;
        }

        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        
        visited[1][0] = 1;
        levels[1][0] = 0;
        dfs(1,0);
        int ans1 = 0, d1 = 1;

        rp(i,1,n+1){
            if(ans1 < levels[i][0]){
                d1 = i;
                ans1 = levels[i][0];
            }
        }

        visited[d1][1] = 1;
        levels[d1][1] = 0;
        dfs(d1,1);

        int ans2 = 0, d2 = d1;
        rp(i,1,n+1){
            if(ans2 < levels[i][1]){
                d2 = i;
                ans2 = levels[i][1];
            }
        }

        visited[d2][2] = 1;
        levels[d2][2] = 0;
        dfs(d2,2);

        int ans = 0;

        rp(i,1,n+1){
            ans = max(ans,max(levels[i][1],levels[i][2])*k - levels[i][0]*c);
        }
        cout << ans << "\n";
    }

    return 0;}