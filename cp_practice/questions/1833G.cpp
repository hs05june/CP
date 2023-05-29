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

int visited[200007], num[200007], parent[200007];
deq graph[200007];

int dfs(int n){
    int ans = 1;
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            parent[i] = n;
            ans += dfs(i);
        }
    }
    return num[n] = ans;
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

        rp(i,0,n+1){visited[i] = 0;parent[i] = 0; graph[i].clear();num[i] = 0;}

        map<pii,int> index;
        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            index[{a,b}] = i;
            index[{b,a}] = i;
        }

        if(n%3!=0){
            cout << "-1\n";
            continue;
        }

        parent[1] = 0;
        visited[1] = 1;

        int x = dfs(1);
        x = n/3 - 1;
        set<pii> possible;
        rp(i,1,n+1){
            if(num[i]%3==0 && num[i]!=n){
                possible.insert({num[i],i});
            }
        }

        if(sz(possible) < (n/3-1)){
            cout << "-1\n";
            continue;
        }

        deq ans;
        while(x--){
            if(possible.empty())break;
            auto y = *(possible.begin());
            possible.erase(possible.begin());
            ans.pb(index[{parent[y.s],y.s}]);
        }


        cout << sz(ans) << "\n";
        for(auto i : ans)cout << i << " ";
        cout << "\n";
    }

    return 0;}