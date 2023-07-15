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

int parent[1007], Size[1007];

int Find(int n){
    if(n == parent[n])return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x==y)return;
    if(Size[x] > Size[y])swap(x,y);
    Size[y] += Size[x];
    parent[x] = y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,d;
    cin >> n >> d;

    rp(i,0,n+1){
        parent[i] = i;
        Size[i] = 1;
    }

    int maxi = 1;
    int z = 1;
    rp(i,0,d){
        int a,b;
        cin >> a >> b;
        int x = Find(a), y = Find(b);
        if(x == y)z++;
        else Union(a,b);
        set<int> par;
        rp(j,1,n+1)par.insert(Find(j));
        deq every;
        for(auto j : par)every.pb(Size[j]);
        sort(all(every));
        reverse(all(every));
        int ans = 0;
        rp(j,0,min(sz(every),z)){
            ans += every[j];
        }
        cout << ans-1 << "\n";
    }

    return 0;}