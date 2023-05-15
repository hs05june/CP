/*
Median in a row-wise sorted Matrix
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.

Example 2:
Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives
us {1,2,3}. Hence, 2 is median.

Your Task:
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)

Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000
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

    int R, C;
    cin >> R >> C;

    vector<deq> matrix;

    rp(i, 0, R)
    {
        deq test;
        rp(j, 0, C)
        {
            int x;
            cin >> x;
            test.pb(x);
        }
        matrix.pb(test);
    }

    int low = 1, high = 2000;
    int neeche = (R * C) / 2, uppar = (R * C) / 2;

    while (high - low > 0)
    {
        int mid = (low + high) / 2;
        int less = 0, more = 0;
        bool present = false;
        for (int i = 0; i < R; i++)
        {
            auto itr1 = lower_bound(matrix[i].begin(), matrix[i].end(), mid);
            auto itr2 = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
            less += (itr1 - matrix[i].begin());
            more += (matrix[i].end() - itr2);
            if (*itr1 == mid)
                present = true;
        }
        if (less <= neeche && more <= uppar)
        {
            if (present)
            {
                cout << mid << "\n";
                return 0;
            }
            else
                high = mid - 1;
        }
        else if (less > neeche)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << "\n";

    return 0;
}