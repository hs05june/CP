/*
132. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.
*/
#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i >= n; i--)
#define ll long long
#define int long long
#define deq vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a, b) lower_bound((a).begin(), (a).end(), b)
const ll M = 1000000007;
using namespace std;

int isPalindrome[2001][2001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;

    int n = s.length();

    int dp[n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (s[j] == s[j + i - 1])
            {
                if (i <= 2)
                {
                    isPalindrome[j][j + i - 1] = 1;
                }
                else
                {
                    isPalindrome[j][j + i - 1] = isPalindrome[j + 1][j + i - 2];
                }
            }
        }
    }

        for(int i = 0; i <= n; i++){
            dp[i] = 0;
        }

        for(int i = n-1; i>=0; i--){
            dp[i] = INT_MAX;
            for(int j = i; j < n; j++){
                if(isPalindrome[i][j]){
                    dp[i] = min(dp[i],1+dp[j+1]);
                }
            }
        }

        cout << (dp[0]-1) << "\n";

    return 0;
}