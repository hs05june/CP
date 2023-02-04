#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int n;
ll level[200005][2];
int levels[2];
deq graph[200005];

void breadth_first_search(int src){
    int visited[n+1] = {0};
    queue<int> bfs;
    bfs.push(levels[src]);
    visited[levels[src]] = 1;
    level[levels[src]][src] = 0;

    while(!bfs.empty()){
        int x = bfs.front();
        for(auto i : graph[x]){
            if(visited[i]==0){
                visited[i] = 1;
                bfs.push(i);
                level[i][src] = 1 + level[x][src];
            }
        }
        bfs.pop();
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i <=200004;i++){
        for(int j = 0; j < 2; j++){
            level[i][j] = LLONG_MAX;
        }
    }

    int m,a,b;

    cin >> n >> m >> levels[0] >> levels[1];

    for(int i = 0; i< m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    breadth_first_search(0);
    breadth_first_search(1);

    int ans = 0;

    for(int i  = 1; i <= n; i++){
        if(level[i][0]==level[i][1] && level[i][0]!=LLONG_MAX && level[i][1]!=LLONG_MAX)ans++;
    }

    cout << ans;

    return 0;}