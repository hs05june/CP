/*
72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
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

int dp[507][507];
    int solve(int n, int m, string word1, string word2){
        if(n<=0 && m<=0)return 0;
        if(n<=0)return m;
        if(m<=0)return n;
        if(dp[n][m]!=-1)return dp[n][m];
        int ans = INT_MAX;
        if(word1[n-1]==word2[m-1]){
            ans = min(ans,solve(n-1,m-1,word1,word2));
        }
        else{
            ans = min(ans,1+solve(n-1,m-1,word1,word2));
        }
        ans = min(ans,1+solve(n-1,m,word1,word2));
        ans = min(ans,1+solve(n,m-1,word1,word2));
        return dp[n][m] = ans;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){
        string word1,word2;
        cin >> word1 >> word2;
        int n = word1.size(), m = word2.size();

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m ;j++){
                dp[i][j] = -1;
            }
        }

        cout << solve(n,m,word1,word2) << "\n";

    }

    return 0;}