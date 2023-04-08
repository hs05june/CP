/*115. Distinct Subsequences
Hard
5.2K
199
Companies
Given two strings s and t, return the number of distinct 
subsequences
 of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.*/

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){
        string s,t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        long long dp[n+1][m+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i <= n; i++)dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m ; j++){
                dp[i][j] = dp[i-1][j]%M;
                if(s[i-1]==t[j-1]){
                    dp[i][j] = (dp[i][j]%M + dp[i-1][j-1]%M)%M;
                }
            }
        }
        cout << dp[n][m]%M << "\n";

    }

    return 0;}