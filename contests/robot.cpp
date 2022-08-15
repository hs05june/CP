#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll graph[3][200007];
int visited[3][200007];
int m;

ll dp[3][200007][200007];

int moves[4][2]={
    {1,0},{0,1},{-1,0},{0,-1}
};

bool check(ll x,ll y){

    bool ans = true;

    for(int i = 1; i < 3; i++){
        for(int j = 1; j <= m; j++){
            if(i==x && j==y){continue;}
            if(visited[i][j] == 0){
                ans = false;
                break;
            }
        }
    }
    return ans;
}

ll solve(ll x, ll y,ll time){

    if(check(x,y)){
        if(graph[x][y]<=time)return time;
        else return graph[x][y];
    }
    
    ll ans = M;
    bool check1 = true;
    for(int i = 0; i<4;i++){
        ll a = x + moves[i][0];
        ll b = y + moves[i][1];

        if(a>0 && a<3 && y>0 && y<=m && visited[a][b]==0){
            if(graph[a][b]<=time){
            visited[a][b] = 1;
            ans = min(ans,solve(a,b,1+time));
            visited[a][b] = 0;
            }
            else{
            visited[a][b] = 1;
            ans = min(ans,solve(a,b,1+graph[a][b]));
            visited[a][b] = 0;
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

while(t--){
    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));
    cin >> m;

    for(int i = 1;i<=2; i++){
        for(int j = 1; j<=m; j++){
            cin >> graph[i][j];
        }
    }
    visited[1][1] = 1;
    cout << solve(1,1,0)<<"\n";}

    return 0;}