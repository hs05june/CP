#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
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

int dp[107][100007];

int solve(int eggs, int floor){
    if(eggs == 1)return floor;
    if(floor == 0)return 0;
    if(dp[eggs][floor] != -1)return dp[eggs][floor];
    int ans = INT_MAX, num = -1;
    for(int i = 1; i <= floor; i++){
        int z = 1 + max(solve(eggs,i-1),solve(eggs - 1, floor - i));
        if(ans > z){
            ans = z;
            num = i;
        }
    }
    // if(floor == 100 && eggs == 3)cout << ans << " " << num << "\n";
    return dp[eggs][floor] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int eggs, floor;
    cin >> eggs >> floor;

    rp(i,0,eggs+1){
        rp(j,0,floor+1){
            dp[i][j] = -1;
        }
    }

    cout << solve(eggs,floor) << "\n";

    return 0;}