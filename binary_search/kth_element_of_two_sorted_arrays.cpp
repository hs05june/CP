/*
K-th element of two sorted Arrays

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.

Example 1:
Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.

Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))


Constraints:
1 <= N, M <= 106
1 <= arr1i, arr2i < INT_MAX
1 <= K <= N+M
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

int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans % mod;
}

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;

    deq ar1, ar2;
    ar1.pb(INT_MIN);
    ar2.pb(INT_MIN);

    rp(i, 0, n)
    {
        int x;
        cin >> x;
        ar1.pb(x);
    }

    rp(i, 0, m)
    {
        int x;
        cin >> x;
        ar2.pb(x);
    }

    ar1.pb(INT_MAX);
    ar2.pb(INT_MAX);

    int low = 0, high = k;

    while (high - low > 0)
    {
        int mid = (low + high) / 2;
        if (mid > n)
        {
            high = mid - 1;
            continue;
        }
        if (k - mid > m)
        {
            low = mid + 1;
            continue;
        }
        if (ar1[mid] <= ar2[k - mid + 1] && ar2[k - mid] <= ar1[mid + 1])
        {
            cout << max(ar1[mid], ar2[k - mid]) << "\n";
            break;
        }
        else if (ar1[mid] > ar2[k - mid + 1])
        {
            high = mid - 1;
        }
        else if (ar1[mid + 1] < ar2[k - mid])
        {
            low = mid + 1;
        }
    }
    cout << max(ar1[low], ar2[k - low]) << "\n";

    return 0;
}