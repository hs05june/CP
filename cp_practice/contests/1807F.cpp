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

int path(string a){
    if(a=="DR")return 0;
    if(a=="DL")return 1;
    if(a=="UR")return 2;
    if(a=="UL")return 3;
}
 
int corner_check(int x){
    if(x==0)return 3;
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 0;
}

int check(int x,int i1,int j1,int n, int m){
    if(x == 0)return i1 == n ? 2 : 1;
    if(x == 1)return i1 == n ? 3 : 0;
    if(x == 2)return i1 == 1 ? 0 : 3;
    if(x == 3)return i1 == 1 ? 1 : 2;
}
 
int update_start(int start, int i1, int j1, int n, int m){
    if((i1==1 && j1==1 && start==3) || (i1==1 && j1==m && start == 2) || (i1==n && j1==1 && start == 1) || (i1==n && j1==m && start==0)){
                start = corner_check(start);
            }
            else{
                start = check(start,i1,j1,n,m);
            }
    return start;
}

pii next(int x, int y, int start){
    if(start==0)return {x+1,y+1};
    if(start == 1)return {x+1,y-1};
    if(start == 2)return {x-1,y+1};
    if(start == 3)return {x-1,y-1};
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,m,i1,j1,i2,j2;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2;
        
        string a; cin >> a;

        int move = path(a);
        int cnt = 0;
    
        map<pii,int> ans[4];
        // ans[0][{i1,i2}] = ans[1][{i1,i2}] = ans[2][{i1,i2}] = ans[3][{i1,i2}] = 0;
        ans[move][{i1,j1}] = 0;

        while(true){
            if(((i1==1 && (move==2 || move==3)) || (i1==n && (move==0 || move==1)) || (j1==m && (move==0 || move==2)) || (j1==1 && (move==1 || move==3)))){
                move = update_start(move,i1,j1,n,m);
                cnt++;
            }

            auto x = next(i1,j1,move);
            i1 = x.f;j1 = x.s;

            if(ans[move].count({i1,j1}))break;
            else{
                ans[move][{i1,j1}] = cnt;
            }
        }

        int ans1 = LLONG_MAX;
        if(ans[0].count({i2,j2}))ans1 = min(ans1, ans[0][{i2,j2}]);
        if(ans[1].count({i2,j2}))ans1 = min(ans1, ans[1][{i2,j2}]);
        if(ans[2].count({i2,j2}))ans1 = min(ans1, ans[2][{i2,j2}]);
        if(ans[3].count({i2,j2}))ans1 = min(ans1, ans[3][{i2,j2}]);

        ans1 == LLONG_MAX ? cout << "-1\n" : cout << ans1 <<"\n";

    }

    return 0;}