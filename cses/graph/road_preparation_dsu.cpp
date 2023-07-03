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

int parent[100007];
int Size[100007];

int Find(int x){
    if(x == parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x==y)return;
    if(Size[x] > Size[y])swap(x,y);
    Size[y]+=Size[x];
    parent[x] = y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,n+1){
        parent[i] = i;
        Size[i] = 1;
    }

    multiset<tuple<int,int,int>> edges;

    rp(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        edges.insert(make_tuple(c,a,b));
    }

    ll ans = 0;

    while(!edges.empty()){
        auto itr = *(edges.begin());
        edges.erase(edges.begin());
        int x = get<0>(itr), y = get<1>(itr), z = get<2>(itr);
        if(Find(y) == Find(z))continue;
        ans += x;
        Union(y,z);
    }

    if(Size[Find(1)]!=n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans << "\n";

    return 0;}