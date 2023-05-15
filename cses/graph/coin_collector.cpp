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

int Size[200007], parent[200007];

int Find(int n){
    if(parent[n]==n)return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(Size[x]>Size[y])swap(x,y);
    Size[y]+=Size[x];
    parent[x] = y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    int ans[n+1];
    rp(i,0,n+1)ans[i] = 0;

    rp(i,1,n+1){
        parent[i] = i;
        Size[i] = 1;
    }

    int coins[n+1];
    coins[0] = 0;
    rp(i,1,n+1)cin >> coins[i];

    while(m--){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    rp(i,1,n+1){
        int x = Find(i);
        ans[x]+=coins[i];
    }

    int k = 0;

    rp(i,1,n+1)k = max(ans[i],k);

    cout << k << "\n";

    return 0;}