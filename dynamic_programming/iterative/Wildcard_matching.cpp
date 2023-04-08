/*44. Wildcard Matching

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

int main()
{
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
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
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    bool check = true;

    for (int i = 1; i <= m; i++)
    {
        if (p1[i - 1] != '*')
            check = false;
        dp[0][i] = check;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p1[j - 1] || p1[j - 1] == '?')
            {
                dp[i][j] |= dp[i - 1][j - 1];
            }
            if (p1[j - 1] == '*')
            {
                dp[i][j] |= dp[i][j - 1];
                dp[i][j] |= dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}