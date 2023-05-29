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

int n,m;
string a[1007];
int arr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

pii closestB(int x, int y){
    int levels[n][m],visited[n][m];
    rp(i,0,n){
        rp(j,0,m)visited[i][j] = 0;
    }  
    queue<pii>bfs;
    visited[x][y] = 1;
    levels[x][y] = 0;
    bfs.push({x,y});
    while(!bfs.empty()){
        auto z = bfs.front();
        bfs.pop();
        rp(i,0,4){
            if(z.f+arr[i][0]<0 || z.f+arr[i][0]>=n || z.s+arr[i][1]<0 || z.s+arr[i][1]>=m)continue;
            if(visited[z.f+arr[i][0]][z.s+arr[i][1]]==0){
                visited[z.f+arr[i][0]][z.s+arr[i][1]] = 1;
                levels[z.f+arr[i][0]][z.s+arr[i][1]] = 1 + levels[z.f][z.s];
                bfs.push({z.f+arr[i][0],z.s+arr[i][1]});
            }
        }
    }
    int x1 = 0, y1 = 0, ans = INT_MAX;
    rp(i,0,n){
        rp(j,0,m){
            if(a[i][j]=='B'){
                if(levels[i][j]<ans){
                    x1 = i;y1 = j;
                    ans = levels[i][j];
                }
            }
        }
    }
    return {x1,y1};  
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        cin >> n >> m;

        rp(i,0,n)cin >> a[i];

        vector<pii> to_check;
        to_check.pb(closestB(0,0));
        to_check.pb(closestB(0,m-1));
        to_check.pb(closestB(n-1,0));
        to_check.pb(closestB(n-1,m-1));
        int ans[n][m];
        rp(i,0,n){
            rp(j,0,m){
                ans[i][j] = 0;
                for(auto k : to_check){
                    ans[i][j] = max(ans[i][j],abs(k.f-i)+abs(k.s-j));
                }
            }
        }

        int x = -1, y = -1, cost = INT_MAX;
        rp(i,0,n){
            rp(j,0,m){
                if(ans[i][j]<cost){
                    cost = ans[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << x+1 << " " << y+1 << "\n";  
    }

    return 0;}