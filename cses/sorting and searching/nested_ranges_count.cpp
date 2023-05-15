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

int fenwick[200007];
int maxi;

void update(int n){
    for(int i = n; i <= maxi; i+= (i&(-i))){
        fenwick[i]++;
    }
}

int sum(int n){
    int ans = 0;
    for(int i = n; i > 0; i -= (i&(-i))){
        ans+=fenwick[i]; 
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    mii hashed;
    map<pii,int> index;
    set<int> elements;
    vector<pii> arr;

    rp(i,0,n){
        int a,b;
        cin >> a >> b;
        arr.pb({a,b});
        index[{a,b}] = i;
        elements.insert(b);
    }

    for(auto i : elements){
        ++maxi;
        hashed[i] = maxi;
    }

    sort(all(arr),[](pii x, pii y){return (x.f==y.f) ? (x.s>y.s):(x.f<y.f);});

    int ans[2][n];

    rep(i,n-1,0){
        int in = index[arr[i]];
        int x = hashed[arr[i].s];
        ans[0][in] = sum(x);
        update(x);
    }

    rp(i,0,maxi+1)fenwick[i] = 0;

    rp(i,0,n){
        int in = index[arr[i]];
        int x = hashed[arr[i].s];
        ans[1][in] = sum(maxi) - sum(x-1);
        update(x);
    }

    rp(i,0,2){
        rp(j,0,n)cout << ans[i][j] << " ";
        cout << "\n";
    }
    
    return 0;}