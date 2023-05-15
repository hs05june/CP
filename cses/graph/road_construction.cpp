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

int parent[100007],Size[100007];

int Find(int n){
    if(n==parent[n])return n;
    return parent[n] = Find(parent[n]);
}

void Union(int x, int y){
    int a = Find(x), b = Find(y);
    if(Size[a]>Size[b])swap(a,b);
    Size[b] += Size[a];
    parent[a] = b;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        rp(i,1,n+1){
            parent[i] = i;
            Size[i] = 1;
        }

        int ans = n, largest = 1;

        rp(i,0,m){
            int a,b;
            cin >> a >> b;
            int x = Find(a), y = Find(b);
            if(x != y){
                ans--;
                Union(x,y);
                largest = max(largest,Size[Find(x)]);
            }
            cout << ans << " " << largest << "\n";
        }

    }

    return 0;}