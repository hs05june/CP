//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

// void make(int n, int tree[], int Size[]){
//     Size[n] = 1;
//     tree[n] = n;
// }

// int find_parent(int n, int tree[]){
//     if(tree[n]==n){
//         return n;
//     }
//     return tree[n] = find_parent(tree[n],tree);
// }

// void Union(int a,int b,int tree[], int Size[]){
//     int x = find(a), y = find(b);
//     if(Size[x]>Size[y])
//         swap(x,y);
        
//         tree[x] = y;
//         Size[y] += Size[x]; 
// }

deq child[200007];
int tree[200007];

void solve(int x,int y){
    if(tree[x]==1 || tree[y]==1){return;}
    tree[x] = 1;
    tree[y] = 1;
   
    int a,b;

    a = (child[x][0]==y) ? child[x][1] : child[x][0];
    b = (child[a][0]==x) ? child[a][1] : child[a][0];

    solve(a,b);

    int c,d;
    c = (child[y][0]==x) ? child[y][1] : child[y][0];
    d = (child[c][0]==y) ? child[c][1] : child[c][0];

    solve(c,d);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        for(int i = 0; i <= (n+1); i++){
            child[i].clear();
            tree[i] = 0;
        }
        
        deque<pii> d;
        bool check = false;

        rp(i,0,n){
            int x,y;
            cin >> x >> y;
            child[x].pb(y);
            child[y].pb(x);
            d.pb({x,y});
            if(x==y || child[x].size()>2 || child[y].size()>2){check = true;}
        }

        if(check){
            cout << "NO\n";
            continue;
        }
        
        for(int i = 0; i < d.size();i++){
            if(tree[d[i].f]==0 && tree[d[i].s]==0){
                solve(d[i].f,d[i].s);
            }
        }        
    
        bool possible = true;
        rep(i,1,n){
            if(tree[i]==0){
                possible = false;
            }
        }

        possible ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;}