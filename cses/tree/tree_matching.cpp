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

deq graph[200007];
ll visited[200007];
ll ans;

ll solve(ll n){
    ll check = 0;
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            ll z = solve(i);
            check |= z;
        }
    }
    if(check){
        ans++;
        return 0;
    }
    else{
        return 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin >> n;

    ans = 0;

    rp(i,1,n){
        ll a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    visited[1] = 1;
    ll z = solve(1);

    cout << ans << "\n";

    return 0;}