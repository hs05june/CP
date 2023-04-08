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

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    deq arr;

    arr.pb(1);
    rp(i, 0, n)
    {
        int x;
        cin >> x;
        arr.pb(x);
    }
    arr.pb(1);

    int dp[n + 2][n + 2];

    for (int i = 0; i <= n + 1; i++)
    {
        dp[0][i] = dp[n + 1][i] = 0;
        dp[i][0] = dp[i][n + 1] = 0;
    }

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = n; i >= 1; i--) // Since pehle dp[k+1][j] ki zaroorat hai, So calculated in reverse order
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j + 1]); // Assumed k is the last element removed in the subarray [i,j] so tab uska left and right is array ke bahar wale honge
            }
        }
    }

    cout << dp[1][n];

    return 0;
}