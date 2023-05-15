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

int child[200007][37];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,q;
    cin >> n >> q;
    
    rep(i,1,n){
        cin >> child[i][0];
    }

    rp(i,1,31){
        rp(j,1,n+1){
            child[j][i] = child[child[j][i-1]][i-1];
        }
    }

    while(q--){
        int x,y;
        cin >> x >> y;
        int ans = x;
        while(y>0){
            int z = (y & (-y));
            ans = child[ans][z];
            y-=z;
        }
        cout << ans << "\n";
    }

    return 0;}