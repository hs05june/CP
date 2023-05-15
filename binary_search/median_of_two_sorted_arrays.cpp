/*4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
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

double odd(vector<int> &nums)
{
    int n = nums.size();
    return nums[n / 2];
}
double even(vector<int> &nums)
{
    int n = nums.size();
    return (double(nums[n / 2 - 1]) + double(nums[n / 2])) / 2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    deq num1, num2;

    num1.push_back(INT_MIN);
    num2.push_back(INT_MIN);
    rp(i, 0, n)
    {
        int x;
        cin >> x;
        num1.pb(x);
    }
    rp(i, 0, m)
    {
        int x;
        cin >> x;
        num2.pb(x);
    }
    num1.push_back(INT_MAX);
    num2.push_back(INT_MAX);

    if (n == 0)
    {
        (m & 1) ? cout << odd(num2) << "\n" : cout << even(num2) << "\n";
        return 0;
    }
    if (m == 0)
    {
        (n & 1) ? cout << odd(num1) << "\n" : cout << even(num1) << "\n";
        return 0;
    }

    int right = (n + m) / 2;
    int left = n + m - right;
    int low = 0, high = left;

    while (high - low > 0)
    {
        int mid = (low + high) / 2;
        if (mid > n)
        {
            high = mid - 1;
            continue;
        }
        if (left - mid > m)
        {
            low = mid + 1;
            continue;
        }

        if (num1[mid] <= num2[left - mid + 1] && num2[left - mid] <= num1[mid + 1])
        {
            if (((n + m) & 1))
            {
                cout << max(num1[mid], num2[left - mid]) << "\n";
                return 0;
            }
            else
            {
                cout << (double(max(num1[mid], num2[left - mid])) + double(min(num1[mid + 1], num2[left - mid + 1]))) / 2 << "\n";
                return 0;
            }
        }
        else if (num1[mid] > num2[left - mid + 1])
        {
            high = mid - 1;
        }
        else if (num2[left - mid] > num1[mid + 1])
        {
            low = mid + 1;
        }
    }

    if (((n + m) & 1))
    {
        cout << max(num1[low], num2[left - low]) << "\n";
    }
    else
    {
        cout << (double(max(num1[low], num2[left - low])) + double(min(num1[low + 1], num2[left - low + 1]))) / 2 << "\n";
    }

    return 0;
}