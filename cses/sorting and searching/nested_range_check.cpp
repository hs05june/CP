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

int fenwick[2][200007];
int maxi;

void update(int n, int x){
    for(int i = n; i<=200005; i += (i & (-i))){
        fenwick[x][i]++;
    }
}

int sum(int n, int x){
    int ans = 0;
    for(int i = n; i > 0; i -= (i & (-i))){
        ans+=fenwick[x][i];
    }
    return ans;
}

bool cmp(pii x, pii y){
    if(x.f!=y.f){
        return x.f<y.f;
    }
    return x.s>y.s;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    vector<pii> arr1,arr2;
    mii hashing;
    map<pii,int> index;
    set<int> elements;

    rp(i,0,n){
        int a,b;
        cin >> a >> b;
        // elements.insert(a);
        elements.insert(b);
        index[{a,b}] = i;
        arr1.pb({a,b});
        arr2.pb({a,b});
    }

    maxi = 0;
    for(auto i : elements){
        ++maxi;
        hashing[i] = maxi;
    }

    sort(all(arr2),[](pii x, pii y){if(x.f!=y.f)return x.f<y.f; return x.s>y.s;});

    int ans1[n],ans2[n];

    rep(i,n-1,0){
        int x = hashing[arr2[i].s];
        int z1 = sum(x,1);
        update(x,1);
        ans1[index[arr2[i]]] = (z1==0) ? 0 : 1;
    }
    rp(i,0,n){
        int x = hashing[arr2[i].s];
        int z2 = i - sum(x-1,0);
        update(x,0);
        ans2[index[arr2[i]]] = (z2==0) ? 0 : 1;
        // cout << index[arr2[i]] << " = " << z2 << "\n";
    }

    rp(i,0,n){
        cout << ans1[i] << " ";
    }

    cout << "\n";

    rp(i,0,n){
        cout << ans2[i] << " ";
    }

    return 0;}
// 1 0 1 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 0 1 1 1 1 1 1 1 0 1 1 1 1 0 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 1 0 1 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 0 1 1 1 1 1 1 1 0 1 1 1 1 0 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 