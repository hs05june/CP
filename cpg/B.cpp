#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
int M = 1000000007;
using namespace std;

int n;
deq tree_child[100007];
deq leaves[100007];
int chips[100007];
int levels[100007];
int visited[100007];

void dfs(int src,int parent){
    levels[src] = 1 + levels[parent];

    if(tree_child[src].empty()){
        return;
    }

    for(auto i : tree_child[src]){
        if(visited[i]==1)continue;
        visited[i] = 1;
        dfs(i,src);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < (n-1); i++){
        int a,b;
        cin >> a >> b;
        tree_child[a].push_back(b);
        tree_child[b].push_back(a);
    }
    levels[0] = -1;
    dfs(1,0);

    for(int i = 1; i<=n; i++){
        cout << levels[i] << "\n";
    }

    return 0;}