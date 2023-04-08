/*312. Burst Balloons

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 
Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100*/

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

    int dp[307][307];
    
    int solve(int low, int high, vector<int>& arr){
        if(low>high)return 0;
        if(dp[low][high]!=-1)return dp[low][high];
        int ans = INT_MIN;
        for(int i = low; i <= high; i++){
            ans = max(ans,solve(low,i-1,arr)+solve(i+1,high,arr)+arr[low-1]*arr[i]*arr[high+1]); // I have assumed that ith was the last balloon to be burst in this section, so balloons left to it must (be low-1) and right wil be (high+1), that is left and right balloons will be out of the considered section
        }
        return dp[low][high] = ans;
    }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    deq arr;

    arr.pb(1);
    rp(i,0,n){
        int x;
        cin >> x;
        arr.pb(x);
    }
    arr.pb(1);

    for(int i = 0; i <= n+1; i++){
            for(int j = 0; j <= n+1; j++){
                dp[i][j] = -1;
            }
        }

    cout << solve(1,n,arr);

    return 0;}