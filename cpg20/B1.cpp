#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define int long long
#define all(x) (x).begin(), (x).end()
ll M = 4000000007;
using namespace std;

int N;
deque<pii> graph[200001];
int ans[200001];
bool visited[200001];

void dijkstra_algorithm(){
    set<pii> bfs;
    
    for(int i = 0; i < 200001;i++){
        ans[i] = LLONG_MAX;
    }

    bfs.insert({0,1});
    ans[1] = 0;

    while(bfs.size()!=0){
        pii z = *(bfs.begin());
        int dist = z.first;
        int parent = z.second;
        bfs.erase(bfs.begin());
        if(visited[parent])continue;
        visited[parent] = true;
        for(auto i : graph[parent]){
            int child = i.second;
            int wt = i.first;
            if((wt+dist)<ans[child]){
                ans[child] = wt + dist;
                bfs.insert({ans[child],child});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int p[N+1] = {0};
    pii lr[N+1] = {{0,0}};

    for(int i = 1; i <= N; i++){
        int a;
        cin >> a >> p[i] >> lr[i].first >> lr[i].second;
        graph[i].push_back({a,i+1});
    }


    for(int i = 1; i <= N; i++){
        for(int j = lr[i].first; j <= lr[i].second && j<i; j++){
            graph[j].push_back({p[j],i});
        }
    }

    dijkstra_algorithm();

    cout << ans[N];

    return 0;}