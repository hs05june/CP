/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/
#include <bits/stdc++.h>
using namespace std;

int dp[2007][2007];
int solve(int n, int m, string s, string p)
{
    if (n < 0 && m < 0)
        return 1;
    if (n < 0 && m >= 0)
    {
        for (int i = m; i >= 0; i--)
        {
            if (p[i] != '*')
                return 0;
        }
        return 1;
    }
    if (m < 0 && n >= 0)
        return 0;
    if (dp[n + 1][m] != -1)
        return dp[n + 1][m];
    int ans = 0;
    if (p[m] == '*')
    {
        ans |= solve(n, m - 1, s, p);
        ans |= solve(n - 1, m, s, p);
    }
    if (s[n] == p[m] || p[m] == '?')
        ans |= solve(n - 1, m - 1, s, p);
    return dp[n + 1][m] = ans;
}

int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    string p1 = "";
    for (int i = 0; i < m; i++)
    {
        if (p[i] != '*')
            p1.push_back(p[i]);
        else
        {
            while (i < m && p[i] == '*')
            {
                ++i;
            }
            --i;
            p1.push_back('*');
        }
    }
    m = p1.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << solve(n - 1, m - 1, s, p1) << "\n";
    return 0;
}
