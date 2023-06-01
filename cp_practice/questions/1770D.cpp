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
const ll M = 998244353;
using namespace std;

int parent[100007], Size[100007];

int Find(int n){
    if(n==parent[n])return n;
    return parent[n] = Find(parent[n]);
}
 
void Union(int a, int b){
    int x = Find(a), y = Find(b);
    if(x==y)return;
    if(Size[x]>Size[y])swap(x,y);
    parent[x] = y;
    Size[y]+=Size[x];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        rp(i,0,n+1){parent[i] = i;Size[i] = 0;}

        int a[n+1],b[n+1];        
        rp(i,1,n+1)cin >> a[i];
        rp(i,1,n+1)cin >> b[i];

        set<int> twice;
        rp(i,1,n+1){
            if(a[i]==b[i]){
                twice.insert(a[i]);
            }
            Union(a[i],b[i]);
            Size[Find(a[i])]++;
        }
        map<int,deq> cnt;
        rp(i,1,n+1){
            cnt[Find(i)].pb(i);
        }
        int ans = 1;
        for(auto i : cnt){
            if(Size[i.f]<sz(i.s))ans=0;
            int x = 2;
            for(auto j : i.s){
                if(twice.count(j))x = n;
            }
            ans = (ans%M * x%M)%M;
        }

        cout << ans%M << "\n";
    }

    return 0;}