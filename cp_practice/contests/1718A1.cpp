#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
// #define int long long
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

int n;
int arr[5007];
int dp[8200][5007];

int solve(int index, int x){
    if(index>n)return 0;
    if(dp[x][index]!=-1)return dp[x][index];

    int ans = 1 + solve(index+1,arr[index+1]);
    ans = min(ans,(x!=0) + solve(index + 1, (x ^ arr[index+1])));

    return dp[x][index] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){
        cin >> n;
        arr[0] = 0;

        rp(i,1,n+1)cin >> arr[i];
        rp(i,0,n+1){
            rp(j,0,8193){
                dp[j][i] = -1;
            }
        }

        // int ans = 0;
        cout << solve(1,arr[1]) << "\n";

    }

    return 0;}