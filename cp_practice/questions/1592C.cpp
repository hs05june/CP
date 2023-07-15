#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define int long long
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

int arr[100007], visited[100007], levels[100007], values[100007];
deq graph[100007];

int dfs(int n){
    int value = arr[n];
    for(auto i : graph[n]){
        if(visited[i]==0){
            visited[i] = 1;
            levels[i] = 1 + levels[n];
            value ^= dfs(i);
        }
    }
    return values[n] = value;
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
            graph[i].clear();
            arr[i] = 0;
            levels[i] = 0;
            visited[i] = 0;
            values[i] = 0;
        }

        rp(i,1,n+1){ cin >> arr[i];}
        rp(i,1,n){
            int a,b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
            visited[i] = 0;
            values[i] = 0;
            levels[i] = 0;
        }

        visited[n] = 0, values[n] = 0, levels[n] = 0;

        visited[1] = 1;
        levels[1] = 0;

        dfs(1);

        if(values[1] == 0){
            cout << "YES\n";
            continue;
        }

        int z = values[1];
        int a = -1, b = -1;

        rp(i,2,n+1){
            if(values[i]==z && levels[i] > b){
                a = i;
                b = levels[i];
            }
        }

        if(a == -1 || k < 3){
            cout << "NO\n";
            continue;
        }

        rp(i,1,n+1) values[i] = 0, visited[i] = 0;

        visited[a] = 1;

        visited[1] = 1;
        levels[1] = 0;
        dfs(1);
        
        bool ans = false;

        rp(i,1,n+1){
            if(values[i] == z)ans = true;
        }

        ans ? cout << "YES\n" : cout << "NO\n";

    }

    return 0;}