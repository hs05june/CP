#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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

int child[200007],visited[200007],cycle[200007];

void dfs(int n){
    int cnt = 1;
    for(int i = 1; i<=n; i++){
        if(visited[i]==0){
            int x = i;
            while(visited[x]==0){
                visited[x] = 1;
                x = child[x];
                cycle[x] = cnt;
            }
            cnt++;
        }
    }
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

        rep(i,1,n){
            visited[i] = 0;
            cycle[i] = 0;
        }

        rep(i,1,n){
            cin >> child[i];
        }

        dfs(n);
        bool check = false;
        mii cnt;
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(cycle[i]==cycle[i-1]){
                check = true;
            }
            cnt[cycle[i]]++;
        }

        for(auto i : cnt){
            ans+=(i.s-1);
        }
        check ? cout << ans - 1 << "\n" : cout << ans + 1 << "\n";
    }

    return 0;}