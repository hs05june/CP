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
ll values[200007], initial[200007], last[200007];
ll euler[400007];
ll tree[800007];
ll t;

void dfs(ll n, ll parent){
    initial[n] = t;
    euler[t] = n;
    ++t;
    for(auto i : graph[n]){
        if(i == parent)continue;
        dfs(i,n);
    }
    last[n] = t;
    euler[t] = n;
    ++t;
}

void make(int node, int start, int end){
    if(start == end){
        tree[node] = euler[start];
        return;
    }
    int mid = (start+end)/2;
    make(2*node,start,mid);
    make(2*node+1,mid+1,end);
    tree[node] = (tree[2*node] + tree[2*node+1]);
}

void update(int node, int start, int end, int pos, int num){
    if(start == end){
        tree[node] += num;
        return;
    }
    tree[node] += num;
    int mid = (start+end)/2;
    if(pos > mid)update(2*node+1,mid+1,end,pos,num);
    else update(2*node,start,mid,pos,num);
}

ll query(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && end <= right){
        return tree[node];
    }
    int mid = (start+end)/2;
    ll q1 = query(2*node,start,mid,left,right);
    ll q2 = query(2*node+1,mid+1,end,left,right);
    return q1 + q2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,m;
    cin >> n >> m;

    rp(i,1,n+1)cin >> values[i];

    rp(i,1,n){
        ll a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(1,0);

    // rp(i,0,2*n)cout << euler[i] << " ";
    // cout << "\n";

    rp(i,1,n+1){
        euler[initial[i]] = values[i];
        euler[last[i]] = -values[i];
    }

    // rp(i,0,2*n)cout << euler[i] << " ";
    // cout << "\n";

    make(1,0,2*n-1);

    while(m--){
        ll x;
        cin >> x;
        if(x==1){
            ll y1,y2;
            cin >> y1 >> y2;
            ll change = y2 - values[y1];
            update(1,0,2*n-1,initial[y1],change);
            update(1,0,2*n-1,last[y1],-change);
            values[y1] = y2;
        }
        else if(x==2){
            ll y1;
            cin >> y1;
            ll ans = query(1,0,2*n-1,0,initial[y1]);
            cout << ans << '\n';
        }
    }

    return 0;}