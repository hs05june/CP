//							  ੴ  ਵਾਹਿਗੁਰੂ 

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

vector<pair<int,pii>> children[200007];
ll ans[200007];
deq d;

void dfs(int root, int a, int b,int expect,int l){
    d.pb(b);
    if(a>=b){
        ans[root] = l;
    }
    else{
        auto z = (--upper_bound(d.begin(),d.end(),a)) - d.begin();
        ans[root] = z;
    }

    for(auto i : children[root]){
        dfs(i.f,a+i.s.f,b+i.s.s,expect,l+1);
    }
    d.pop_back();
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        rep(i,0,n+1){
            children[i].clear();
        }

        rep(i,2,n){
            int p,a,b;
            cin >> p >> a >> b;
            children[p].pb({i,{a,b}});
        }

        deq d;
        d.clear();
        dfs(1,0,0,0,0);

        rep(i,2,n){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;}