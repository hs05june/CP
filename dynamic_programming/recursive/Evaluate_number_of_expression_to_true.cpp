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

int dp[160][160][2];
int TRUE(int low,int high, string A);
int FALSE(int low,int high, string A);

int TRUE(int low, int high, string A){
    if(low>high)return (0%M);
    if(low==high){
        if(A[low]=='T')return 1%M;
        else return 0%M;
    }
    if(dp[low][high][1]!=-1)return dp[low][high][1];
    int ans = 0;
    for(int i = low+1; i<=high; i+=2){
        if(A[i]=='|'){
            ans = (ans%M + (TRUE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (TRUE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (FALSE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
        }
        else if(A[i]=='&'){
            ans = (ans%M + (TRUE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
        }
        else if(A[i]=='^'){
            ans = (ans%M + (TRUE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (FALSE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
        }
    }
    return dp[low][high][1] = ans%M;
}

int FALSE(int low, int high, string A){
    if(low>high)return 0%M;
    if(low==high){
        if(A[low]=='F')return 1%M;
        else return 0%M;
    }
    if(dp[low][high][0]!=-1)return dp[low][high][0];
    int ans = 0;
    for(int i = low+1; i<=high; i+=2){
        if(A[i]=='|'){
            ans = (ans%M + (FALSE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
        }
        else if(A[i]=='&'){
            ans = (ans%M + (FALSE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (TRUE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (FALSE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
        }
        else if(A[i]=='^'){
            ans = (ans%M + (TRUE(low,i-1,A)%M * TRUE(i+1,high,A)%M)%M)%M;
            ans = (ans%M + (FALSE(low,i-1,A)%M * FALSE(i+1,high,A)%M)%M)%M;
        }
    }
    return dp[low][high][0] = ans%M;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    string A;
    cin >> A;

    int n = A.length();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    cout << TRUE(0,n-1,A)%M << "\n";

    return 0;}