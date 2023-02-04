#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
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
int dp[1007][1007];
int a[1007][1007];

int solve(int x, int y){
    if(x>=n+1)return y;

    if(a[x][y]==1){
        a[x][y] = 2;
        return solve(x,y+1);
    }
    else if(a[x][y]==3){
        a[x][y] = 2;
        return solve(x,y-1);
    }
    else if(a[x][y]==2){
        return solve(x+1,y);
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int k;
    cin >> n >> m >> k;

    rep(i,0,1000){
        rep(j,0,1000){
            dp[i][j] = -1;
        }
    }

    rep(i,1,n){
        rep(j,1,m){
            cin >> a[i][j];
        }
    }

    rp(i,0,k){
        int x;
        cin >> x;
        cout << solve(1,x) << " ";
    }

    return 0;}