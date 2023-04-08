/*
We are given an array ‘ARR’ with N positive integers. We need to partition the array into two subsets such that the absolute difference of the sum of elements of the subsets is minimum.

We need to return only the minimum absolute difference of the sum of elements of the two partitions.

Constraints:
    1 <= N <= 10^3
    0 <= Arr[i] <= 10^3
    0 <= SUM <= 10^4

Example 1 : 
    Input - 
    4
    1 2 3 4
    Output -
    0
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
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
using namespace std;

int n;
int dp[1007][10007];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    cin >> n;
    deq arr;

    rp(i,0,n){
        int x;
        cin >> x;
        arr.pb(x);
    }

    int sum = 0;
	for(auto i : arr)sum+=i;
	
	for(int i = 0; i <= n; i++)dp[i][0] = 1;

    for(int i = 1; i<=n;i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j-arr[i-1]>=0)dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }

    int x1 = sum/2;
    int x2 = sum - x1;

    while(dp[n][x2]!=1){
        x2++; // to check if this sum is possible
    }

    x1 = sum - x2;


    return 0;}