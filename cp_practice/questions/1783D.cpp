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
const ll M = 998244353;
using namespace std;

int n;
int arr[307];

int dp[307][180050];

int solve(int ind,int value){
    if(ind==n)return 1%M;
    if(dp[ind][value+90010]!=-1)return dp[ind][value+90010];
    if(value==0){
        return solve(ind+1,arr[ind+1])%M;
    }
    int ans = 0%M;
    ans = (ans%M + solve(ind+1, arr[ind+1]-value)%M)%M;
    ans = (ans%M + solve(ind+1, arr[ind+1]+value)%M)%M;
    return dp[ind][value+90010] = ans%M;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    rp(i,0,307){
        rp(j,0,180050)dp[i][j] = -1;
    }

    cin >> n;
    rp(i,1,n+1)cin >> arr[i];

    cout << solve(2,arr[2])%M << "\n";

    return 0;}