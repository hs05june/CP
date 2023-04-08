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

int dp[300007];
int arr[300007];

int solve(int n){
    if(dp[n]!=-1)return dp[n];

    int ans = 1;

    for(int i = n-1; i >=max(0LL,n-256LL);i--){
        if((arr[i] ^ n) < (arr[n] ^ i)){ans = max(ans,1 + solve(i));}
    }

    return dp[n] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        rp(i,0,n){
            cin >> arr[i];
        }

        rp(i,0,n+1){
            dp[i] = -1;
        }

        int ans = 1;

        rp(i,0,n){
            ans = max(ans,solve(i));
        }

        cout << ans << "\n";
    }

    return 0;}