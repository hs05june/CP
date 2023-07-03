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

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char path[4] = {'L','R','U','D'};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    string a[n];

    int levelm[n][m], levela[n][m], visited[n][m];

    rp(i,0,n)cin >> a[i];

    queue<pii> bfsm, bfsa;

    rp(i,0,n){
        rp(j,0,m){
            levela[i][j] = levelm[i][j] = INT_MAX;
            visited[i][j] = 0;
            if(a[i][j] == 'M'){
                levelm[i][j] = 0;
                visited[i][j] = 1;
                bfsm.push({i,j});
            }
            if(a[i][j]=='A'){
                levela[i][j] = 0;
                bfsa.push({i,j});
            }
        }
    }

    while(!bfsm.empty()){
        auto x = bfsm.front().f, y = bfsm.front().s;
        bfsm.pop();
        rp(i,0,4){
            int x1 = x + moves[i][0], y1 = y + moves[i][1];
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && visited[x1][y1] == 0 && a[x1][y1] != '#'){
                levelm[x1][y1] = 1 + levelm[x][y];
                visited[x1][y1] = 1;
                bfsm.push({x1, y1});
            }
        }
    }

    rp(i,0,n){
        rp(j,0,m)visited[i][j] = 0;
    }

    visited[bfsa.front().f][bfsa.front().s] = 1;

    while(!bfsa.empty()){
        auto x = bfsa.front().f, y = bfsa.front().s;
        bfsa.pop();
        rp(i,0,4){
            int x1 = x + moves[i][0], y1 = y + moves[i][1];
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && visited[x1][y1] == 0 && a[x1][y1] != '#' && levelm[x1][y1] > (1 + levela[x][y])){
                levela[x1][y1] = 1 + levela[x][y];
                visited[x1][y1] = 1;
                bfsa.push({x1, y1});
            }
        }
    }

    pii ans = {-1,-1};

    rp(i,0,n){
        if(visited[i][0] == 1){
            ans.f = i;
            ans.s = 0;
            break;
        }
        if(visited[i][m-1] == 1){
            ans.f = i;
            ans.s = m-1;
            break;
        }
    }

    rp(i,0,m){
        if(visited[0][i] == 1){
            ans.f = 0;
            ans.s = i;
            break;
        }
        if(visited[n-1][i] == 1){
            ans.f = n-1;
            ans.s = i;
            break;
        }
    }

    if(ans.f == -1 && ans.s == -1){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << levela[ans.f][ans.s] << "\n";
    // cout << ans.f << " " << ans.s << "\n";
    string ans1 = "";
    while(levela[ans.f][ans.s] != 0){
        rp(i,0,4){
            int x1 = (ans.f + moves[i][0]), y1 = (ans.s + moves[i][1]);
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && visited[x1][y1] == 1 && levela[x1][y1] == (levela[ans.f][ans.s]-1)){
                ans1.pb(path[i]);
                ans = {x1,y1};
                break;
            }
        }
    }

    reverse(all(ans1));
    cout << ans1 << "\n";

    return 0;}