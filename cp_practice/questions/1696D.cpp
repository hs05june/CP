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

pii sparse[2][20][500007];
deq graph[500007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int arr[n+1];
        arr[0] = 0;
        rp(i,0,n+1)graph[i].clear();
        rp(i,1,n+1){cin >> arr[i];}
        int next[n+1][2];
        rp(i,0,n+1){next[i][0] = n+1; next[i][1] = n+1;}

        stack<pii> st[2];

        rp(i,1,n+1){
            while(!st[1].empty() && st[1].top().f < arr[i]){
                int x = st[1].top().s;
                next[x][1] = i;
                st[1].pop();
            }
            st[1].push({arr[i],i});
            while(!st[0].empty() && st[0].top().f > arr[i]){
                int x = st[0].top().s;
                next[x][0] = i;
                st[0].pop();
            }
            st[0].push({arr[i],i});
        }

        rp(i,1,n+1){
            sparse[0][0][i] = sparse[1][0][i] = {arr[i],i};
        }

        rp(j,1,20){
            rp(i,1,n+1){
                int k = j-1;
                if((i + (1<<k)) > n+5)break;
                sparse[0][j][i] = min(sparse[0][k][i],sparse[0][k][i+(1<<k)]);
                sparse[1][j][i] = max(sparse[1][k][i],sparse[1][k][i+(1<<k)]);
            }
        }

        rp(i,1,n+1){
            int x = next[i][1];
                int y = 0, l = i;
                int siz = x - i;
                pii ans = {INT_MAX,0};
                while((1<<y)<=siz){
                    if(((1<<y)&siz)!=0){
                        ans = min(ans,sparse[0][y][l]);
                        l+=(1<<y);
                    }
                    ++y;
                }
                if(i!=ans.s){
                    graph[i].pb(ans.s);
                }
            x = next[i][0];
                 y = 0, l = i;
                siz = x - i;
                ans = {INT_MIN,0};
                while((1<<y)<=siz){
                    if(((1<<y)&siz)!=0){
                        ans = max(ans,sparse[1][y][l]);
                        l+=(1<<y);
                    }
                    ++y;
                }
                if(i!=ans.s){
                    graph[i].pb(ans.s);
                }
        }

        int levels[n+1], visited[n+1];
        rp(i,1,n+1)visited[i] = 0;
        queue<int> bfs;
        bfs.push(1);
        visited[1] = 1;
        levels[1] = 0;
        while(!bfs.empty()){
            int i = bfs.front();
            bfs.pop();
            for(auto j : graph[i]){
                if(visited[j]==0){
                    visited[j] = 1;
                    levels[j] = 1 + levels[i];
                    bfs.push(j);
                }
            }
        }
        cout << levels[n] << "\n";
    }
    return 0;}