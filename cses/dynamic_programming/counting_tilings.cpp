#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

int dp[(1<<10)][1007];

deq nextMasks[1<<10];

void generate_masks(int mask, int n){
    rp(i,0,(1<<n)){
        bool check = true;
        rp(j,0,n){
            if((((1<<j) & mask) != 0)){
                if(((1<<j) & i) != 0){check = false;break;}
            }
            else if((((1<<j) & mask) == 0) && (((1<<j) & i) == 0)){
                if((j+1) >= n || ((1<<(j+1)) & i) != 0 || ((1<<(j+1)) & mask) != 0){check = false;break;}
                else ++j;
            }
        }
        if(check){
            nextMasks[mask].pb(i);
        }
    }
}

int solve(int mask, int col, int n, int m){
    if(col > m)return (mask==0);

    if(dp[mask][col] != -1) return dp[mask][col];

    ll ans = 0;

    for(auto i : nextMasks[mask]){
        ans = (ans%M + solve(i,col+1,n,m)%M)%M;
    }
    return dp[mask][col] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    ll n,m;
    cin >> n >> m;

    rp(i,0,1<<n){
        rp(j,0,m+1)dp[i][j] = -1;
    }

    rp(i,0,(1<<n)){
        generate_masks(i,n);
    }

    cout << solve(0,1,n,m)%M << "\n";

    return 0;}