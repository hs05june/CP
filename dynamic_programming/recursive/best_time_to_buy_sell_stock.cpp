/*
    188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
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

 int dp[1007][107][2];
    
    int solve(int n, int k, int buy, vector<int>& prices){
        if(n>=prices.size() || k<=0)return 0;
        if(dp[n][k][buy]!=-1)return dp[n][k][buy];
        int ans = solve(n+1,k,buy,prices);
        if(buy==0){
            ans = max(ans,-prices[n]+solve(n+1,k,1,prices));
        }
        if(buy==1){
            ans = max(ans,prices[n]+solve(n+1,k-1,0,prices));
        }
        return dp[n][k][buy] = ans;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    // cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;
        
        deq prices;

        rp(i,0,n){
            int x;
            cin >> x;
            prices.pb(x);
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }

        cout << max(solve(1,k,0,prices),-prices[0]+solve(1,k,1,prices)) << "\n";

    }

    return 0;}