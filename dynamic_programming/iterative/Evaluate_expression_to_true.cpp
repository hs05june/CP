/*
Evaluate Expression To True
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false.
Return the number of ways to evaluate the expression modulo 103 + 3.

Input Format:
The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false

Output:
Return an integer, representing the number of ways to evaluate the string.

Constraints:
1 <= length(A) <= 150

Example:
Input 1:
    A = "T|F"
Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"
    
Output 2:
    0
    
Explanation 2:
    There is no way to evaluate A to a true statement.
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string A;
    cin >> A;

    int n = A.length();
    
    int dp[n][n][2];
    for(int i = n-1; i>=0; i-=2){
        for(int j = i; j < n; j+=2){
            dp[i][j][0] = dp[i][j][1] = 0;
            if(i==j){
                dp[i][j][0] = (A[i] == 'T') ? 0 : 1;
                dp[i][j][1] = (A[i] == 'T') ? 1 : 0;
                continue;
            }
            for(int k = i+1; k <= j; k+=2){
                if(A[k]=='|'){
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][1]%M * dp[k+1][j][1]%M)%M)%M;
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][1]%M * dp[k+1][j][0]%M)%M)%M;
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][0]%M * dp[k+1][j][1]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][0]%M * dp[k+1][j][0]%M)%M)%M;
                }
                else if(A[k]=='&'){
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][1]%M * dp[k+1][j][1]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][1]%M * dp[k+1][j][0]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][0]%M * dp[k+1][j][1]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][0]%M * dp[k+1][j][0]%M)%M)%M;
                }
                else if(A[k]=='^'){
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][0]%M * dp[k+1][j][1]%M)%M)%M;
                    dp[i][j][1] = (dp[i][j][1]%M + (dp[i][k-1][1]%M * dp[k+1][j][0]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][0]%M * dp[k+1][j][0]%M)%M)%M;
                    dp[i][j][0] = (dp[i][j][0]%M + (dp[i][k-1][1]%M * dp[k+1][j][1]%M)%M)%M;
                }
            }
        }
    }

    cout << dp[0][n-1][1]%M;

    return 0;}