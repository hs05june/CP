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
int score[200007];
map<pii,int> dp;

int dfs(int n, int parent, int k){
    if(k==0)return 0;
    if(dp.count({n,k})){
        return dp[{n,k}];
    }
    int children = (graph[n].size() - (parent != 0));
    if(children==0)return k*score[n];
    int x = ceil(((long double)k)/children);
    int y = floor(((long double)k)/children);
    mii large;
    mii small;
    for(auto i : graph[n]){
        if(i==parent)continue;;
        int ans1 = dfs(i,n,x);
        large[i] = ans1;
    }
    for(auto i : graph[n]){
        if(i==parent)continue;
        int ans1 = dfs(i,n,y);
        small[i] = ans1;
    }
    int par1 = k%children;
    int ans = 0;
    set<pii> select;
    for(auto i : large){
        select.insert({small[i.f]-i.s,i.f});
    }
    for(auto i : select){
        if(par1 > 0){
            par1--;
            ans += large[i.s];
        }
        else ans+=small[i.s];
    }
    return dp[{n,k}] = (ans + k*score[n]);
    // return (ans + k*score[n]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;
        dp.clear();
        rp(i,0,n+1)graph[i].clear();

        rp(i,2,n+1){
            int x;
            cin >> x;
            graph[i].pb(x);
            graph[x].pb(i);
        }

        rp(i,1,n+1)cin >> score[i];

        cout << dfs(1,0,k) << "\n";

    }

    return 0;}