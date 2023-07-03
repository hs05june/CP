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
ll euler[400007];
ll t;
ll values[200007];
ll initial[200007], last[200007];
ll tree[800007];

ll dfs(int n, int parent){
    initial[n] = t;
    last[n] = t;
    euler[t] = n;
    ++t;
    for(auto i : graph[n]){
        if(i != parent){
            last[n] = max(last[n],dfs(i,n));
        }
    }
    return last[n];
}

void make(ll node, ll start, ll end){
    if(start == end){
        tree[node] = values[euler[start]];
        return;
    }

    ll mid = (start+end)/2;
    make(2*node,start,mid);
    make(2*node+1,mid+1,end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(ll node, ll start, ll end, ll pos, ll num){
    if(start == end){
        tree[node] += num;
        return;
    }
    tree[node] += num;
    ll mid = (start+end)/2;
    if(pos > mid) update(2*node+1,mid+1,end,pos,num);
    else update(2*node,start,mid,pos,num);
}

ll query(ll node, ll start, ll end, ll left, ll right){
    if(start > right || end < left){
        return 0;
    }
    if(start >= left && end <= right){
        return tree[node];
    }
    ll mid = (start+end)/2;
    ll q1 = query(2*node,start,mid,left,right);
    ll q2 = query(2*node+1,mid+1,end,left,right);
    return (q1+q2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,m;
    cin >> n >> m;
    t = 0;
    rp(i,1,n+1){
        cin >> values[i];
    }

    rp(i,1,n){
        ll a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ll x = dfs(1,0);
    make(1,0,n-1);
    // rp(i,1,n+1){
    //     cout << euler[i] << " ";
    // }
    // cout << "\n";
    // rp(i,1,n+1){
    //     cout << initial[i] << " " << last[i] << "\n";
    // }

    while(m--){
        ll x;
        cin >> x;
        if(x == 1){
            ll s1,s2;
            cin >> s1 >> s2;
            ll change = (s2 - values[s1]);
            values[s1] = s2;
            update(1,0,n-1,initial[s1],change);
        }
        else if(x==2){
            ll s1;
            cin >> s1;
            cout << query(1,0,n-1,initial[s1],last[s1]) << "\n";
        }
    }

    return 0;}