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

ll dp[100007];
ll child[100007];
deq graph[100007];

ll dfs(int n){
    if(dp[n]!=-1)return dp[n];
    ll ans = INT_MIN;
    for(auto i : graph[n]){
        ll x = dfs(i);
        if(ans < x){
            ans = x;
            child[n] = i;
        }
    }
    return dp[n] = 1 + ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,n+1)dp[i] = -1;

    dp[n] = 1;

    rp(i,0,m){
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
    }

    ll ans = dfs(1);

    if(ans <= 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << ans << "\n";

    int x = 1;
    deq path;
    while(x!=0){
        path.pb(x);
        x = child[x];
    }

    for(auto i : path){
        cout << i << " ";
    }

    cout << "\n";

    return 0;}