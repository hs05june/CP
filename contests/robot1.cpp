#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll graph[2][200007];
int visited[2][200007];
int m;

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

ll solve(ll x, ll y,ll time,int visit){

       if(check(x,y)){
        if(graph[x][y]<=time)return time;
        else return graph[x][y];
    }
    
    ll ans = M;
    bool check1 = true;

    ll x1 = (x+1)%2;

    if(visit!=2){if(visited[x1][y] == 0){
        visited[x1][y] = 1;
        if(graph[x1][y]<=time)ans = min(ans,solve(x1,y,1+time,1));
        else ans = min(ans,solve(x1,y,1+graph[x1][y],1));
        visited[x1][y] = 0;
    }
}
    ll y1 = (y==m) ? y-1 : y+1;

    if(visited[x][y1] == 0){
        visited[x][y1] = 1;
        if(graph[x][y1]<=time){ans = min(ans,solve(x1,y,1+time,2));}
        else ans = min(ans,solve(x1,y,1+graph[x1][y],2));
        visited[x][y1] = 0;
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

    for(int i = 0;i<2; i++){
        for(int j = 1; j<=m; j++){
            cin >> graph[i][j];
        }
    }
    visited[1][1] = 1;
    cout << solve(1,1,0,0)<<"\n";}

    return 0;}