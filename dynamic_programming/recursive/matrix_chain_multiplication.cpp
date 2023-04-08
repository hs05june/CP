/*
Matrix Chain Multiplication
HardAccuracy: 49.64%Submissions: 77K+Points: 8
Attend free LIVE Webinars with Summer Skill-Up Sessions! Enroll Now!  

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
*/

// If two matrices of order p*q and m*n have to be multiplied, then

// n = p is necessary
// resultant matrix p*n
// number of multiplications  = m*n*q

//Logic - For multiplying say 4 matrix = you may do A1*(A2*A3*A4) or (A1*A2)*(A3*A4) or (A1*A2*A3)*A4 In sabme se minimum nikaalna h

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

long long dp[207][207];
    long long solve(int n, int m, int arr[]){
        if(n==m)return 0;
        if(n>m)return INT_MAX;
        if(dp[n][m]!=-1)return dp[n][m];
        long long ans = LLONG_MAX;
        
        for(int i = n; i<m; i++){
            ans = min(ans,solve(n,i,arr)+solve(i+1,m,arr)+arr[n-1]*arr[i]*arr[m]);
        }
        
        return dp[n][m] = ans;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    int N;
    cin >> N;

    int arr[N+1];

    rp(i,0,N+1){
        cin >> arr[i]; // Order of ith matrix = arr[i-1]*arr[i]
    }

    for(int i = 0; i<=N+1; i++){
            for(int j = 0; j <= N+1; j++){
                dp[i][j] = -1;
        }
    }

    cout << solve(1,N,arr);

    
    return 0;}