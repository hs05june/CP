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

deq edges[100007];
int visited[2][100007];

void dfs(int n, int m){
    for(auto i : edges[n]){
        if(visited[m][i]==1)continue;
        visited[m][i] = 1;
        dfs(i,m);
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

        rp(i,0,n){
            edges[i].clear();
            visited[0][i] = 0;
            visited[1][i] = 0;
        }

        pii arr[2][n];
        rp(i,0,2){
            rp(j,0,n){
                cin >> arr[i][j].f;
                arr[i][j].s = j;
            }
        }

        sort(arr[0],arr[0]+n);
        sort(arr[1],arr[1]+n);

        // rp(i,0,2){
        //     rp(j,0,n){
        //         cout << arr[i][j].s << "," << arr[i][j].f << " ";
        //     }
        //     cout << "\n";
        // }

        rp(i,0,2){
            rp(j,0,n-1){
                edges[arr[i][j].s].pb(arr[i][j+1].s);
            }
        }

        reverse(arr[0],arr[0]+n);
        reverse(arr[1],arr[1]+n);

        visited[0][arr[0][0].s] = 1;
        dfs(arr[0][0].s, 0);
        visited[1][arr[1][0].s] = 1;
        dfs(arr[1][0].s, 1);

        rp(i,0,n){
            cout << (visited[0][i] | visited[1][i]);
        }

        cout << "\n";
    }

    return 0;}