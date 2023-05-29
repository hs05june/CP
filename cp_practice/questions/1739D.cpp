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

int parent[200007][20], depth[200007], visited[200007];
deq graph[200007];

void dfs(int n){
    for(auto i : graph[n]){
        depth[i] = 1 + depth[n];
        dfs(i);
    }
}

int binary_jumping(int n, int x){
    int i = 0;
    int ans = n;
    while((1<<i) <= x){
        if(((1<<i)&x)!=0){
            ans = parent[ans][i];
        }
        ++i;
    }
    return ans;
}

void update(set<pii>& heights, int x){
    visited[x] = 1;
    heights.erase({(-depth[x]),x});
    for(auto i : graph[x]){
        if(visited[i]==0)update(heights,i);
    }
}

int check(int mid, int n, int k){
    set<pii> heights;
    rp(i,0,n+1)visited[i] = 0;
    rp(i,1,n+1){
        if(depth[i]>mid)heights.insert({-depth[i],i});
    }
    int ans = 0;
    while(!(heights.empty())){
        auto a = *(heights.begin());
        int h = (-a.f), node = a.s;
        int x = binary_jumping(node,mid-1);
        update(heights,x);
        ans++;
    }
    return (ans<=k);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,k;
        cin >> n >> k;

        rp(i,0,n+1){
            depth[i] = 0;
            rp(j,0,20)parent[i][j] = 0;
            graph[i].clear();
        }
        parent[1][0] = 1;
        rp(i,2,n+1){
            cin >> parent[i][0];
            graph[parent[i][0]].pb(i);
        }

        rp(i,1,20){
            rp(j,1,n+1){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }

        depth[1] = 0;
        dfs(1);

        int low = 1, high = 0;
        rp(i,1,n+1)high = max(high,depth[i]);

        while(high-low>1){
            int mid = (low+high)/2;
            if(check(mid,n,k)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        if(check(low,n,k))cout << low << "\n";
        else if(check(high,n,k)) cout << high << "\n";
    }

    return 0;}