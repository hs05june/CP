//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t; cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n+1] = {0};
        rep(i,1,n){cin >> a[i];}

        int dp[n+1] = {0};
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            if((i-1-a[i])>=0 && dp[i]!=1){dp[i] = dp[i-1-a[i]];}
            if((i+a[i])<=n && dp[i+a[i]]!=1)dp[i+a[i]] = dp[i-1];
        }

        dp[n] ? cout << "Yes\n" : cout << "No\n";

    }

    return 0;}