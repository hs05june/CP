/*
115. Distinct Subsequences

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

int dp[1007][1007];

long long solve(int n, int m, string s, string t){
        if(m<0)return 1%M;
        if(n<0)return 0%M;
        if(dp[n][m]!=-1)return dp[n][m]%M;
        
        int ans  = solve(n-1,m,s,t)%M;

        if(s[n]==t[m]){
            ans = (ans%M + solve(n-1,m-1,s,t)%M)%M;
        }
        return dp[n][m] = (ans%M);
     }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){

        string s,t;
        cin >> s >> t;

        int n = s.length(), m = t.length();

        rp(i,0,n+1){
            rp(j,0,m+1){
                dp[i][j] = -1;
            }
        }

        cout << solve(n-1,m-1,s,t) << '\n';

    }

    return 0;}