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

deq primes;
int dp[1000007];

void solve(int n){
    for(int i = n+1; i >= 1; i--){
        int x = n / i;
        dp[i] = (x*(x-1))/2;
        for(int j = 2*i; j <= n; j+=i){
            dp[i] -= dp[j];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        solve(n);
        int ans = 0;

        for(int i = n+1; i >= 2; i--){
            if(m < (i - 1))continue;
            int can = dp[i];
            int times = can / (i-1);
            int z = min(m / (i-1), times);
            m -= z*(i-1);
            ans += (z*i);
        }

        if(m!=0)cout << "-1\n";
        else cout << ans << "\n";
    }

    return 0;}