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

int dp[100007][107];
int arr[100007];

int solve(int ind, int value, int n, int m){
    if(ind==n-1 && (arr[ind] == 0 || arr[ind] == value))return 1%M;
    if(dp[ind][value] != -1) return dp[ind][value];
    if(arr[ind] != 0 && arr[ind] != value){
        return dp[ind][value] = 0;
    }
    ll ans = 0;
    ans = (ans%M + 0LL + solve(ind+1,value,n,m)%M)%M;
    if(value+1 <= m) ans = (ans%M + 0LL + solve(ind+1,value+1,n,m)%M)%M;
    if(value-1 >= 1) ans = (ans%M + 0LL + solve(ind+1,value-1,n,m)%M)%M;
    return dp[ind][value] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin >> n >> m;

    rp(i,0,n){
        cin >> arr[i];
    }

    rp(i,0,n+1){
        rp(j,0,m+1){
            dp[i][j] = -1;
        }
    }

    ll ans = 0;
    rp(i,1,m+1){
        ans = (ans%M + solve(0,i,n,m)%M)%M;
    }

    cout << ans << "\n";

    return 0;}