#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

deq child[200007];
pii values[200007];
int ans = 0;

ll dfs(int n){
    // if(child[n].empty()){
    //     return values[n].s;
    // }
    ll sum = 0;
    for(auto i : child[n]){
        sum += dfs(i);
    }
    if(sum < values[n].f){
        ++ans;
        return values[n].s;
    }
    return min(sum,values[n].s);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;
        ans = 0;
        rep(i,0,n){
            child[i].clear();
            values[i] = {0,0};
        }

        rep(i,2,n){
            int x;
            cin >> x;
            child[x].pb(i);
        }

        rep(i,1,n){
            int x,y;
            cin >> x >> y;
            values[i] = {min(x,y),max(x,y)};
        }

        ll z = dfs(1);
        cout << ans << "\n";
    }

    return 0;}