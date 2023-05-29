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

set<int> for_ans[7];

void generate_for_ans(int in, int x, int bit){
    if(in>=6){
        for_ans[bit].insert(x);
        return;
    }
    generate_for_ans(in+1,x,bit);
    generate_for_ans(in+1, (x | ((1LL)<<in)), bit+1);
}

int dp[200020][64];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    generate_for_ans(0,0,0);

    while(t--){

        int n,k;
        cin >> n>> k;

        int arr[n+1];
        arr[0] = 0;
        rp(i,1,n+1)cin >> arr[i];

        rp(i,0,n+1){
            rp(j,0,64)dp[i][j] = 0%M;
        }

        rp(i,1,n+1)dp[i][arr[i]] = 1%M;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 64; j++){
                dp[i][j] = (dp[i][j]%M + dp[i-1][j]%M)%M;
                dp[i][j&arr[i]] = (dp[i][j&arr[i]]%M + dp[i-1][j]%M)%M;
            }
        }

        int ans = 0;

        for(auto i : for_ans[k]){
            ans = (ans%M + dp[n][i]%M)%M;
        }

        cout << ans%M << "\n";


    }

    return 0;}