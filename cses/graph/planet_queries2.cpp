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

int child[200007], levels[200007], component[200007], cycle[200007];

void dfs(int n, int comp){
    component[n] = comp;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,q;
    cin >> n >> q;

    rp(i,1,n+1){
        cin >> child[i];
    }

    rp(i,1,n+1){

    }

    while(q--){

    }

    return 0;}