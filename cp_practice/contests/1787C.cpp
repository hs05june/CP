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

int dp[200007][2], values[200007][2];

int solve(int index, int i, int n){
    if(index>=n)return 0;

    if(dp[index][i]!=-1)return dp[index][i];

    int ans1 = values[index][i]*values[index+1][0] + solve(index+1, 1, n);
    int ans2 = values[index][i]*values[index+1][1] + solve(index+1, 0, n);

    return dp[index][i] = min(ans1,ans2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n,s;
        cin >> n >> s;

        int a[n+1];

        a[0] = 0;

        for(int i = 0; i <= n; i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
            values[i][0] = 0;
            values[i][1] = 0;
        }        

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        values[1][0] = values[1][1] = a[1];
        values[n][0] = values[n][1] = a[n];

        for(int i = 2; i<=n-1; i++){
            if(a[i]>=s){
                values[i][0] = s;
                values[i][1] = a[i]-s;
            }
            else{
                values[i][0] = 0;
                values[i][1] = a[i];
            }
        }

        cout << min(solve(1,0,n),solve(1,1,n)) << "\n";

    }

    return 0;}