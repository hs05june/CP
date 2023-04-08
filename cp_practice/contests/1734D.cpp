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

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n + 1];
        arr[0] = 0;
        deq final_arr;
        rp(i, 1, n + 1) cin >> arr[i];

        int left = k - 1, right = k + 1, current = arr[k];

        int mini_left = 0, mini_right = 0, k1 = -1, k2 = -1;

        while (left >= 1 && right <= n)
        {
            if (k1 == -1)
            {
                int x = 0;
                k1 = left;
                while (k1 > 0)
                {
                    x += arr[k1];
                    mini_left = min(x, mini_left);
                    --k1;
                    if (x >= 0)
                        break;
                }
            }
            if (mini_left + current >= 0 && k1 != -1)
            {
                while (left != k1)
                {
                    current += arr[left];
                    --left;
                }
                left = k1;
                mini_left = 0;
                k1 = -1;
                continue;
            }
            if (k2 == -1)
            {
                int x = 0;
                k2 = right;
                while (k2 <= n)
                {
                    x += arr[k2];
                    mini_right = min(mini_right, x);
                    ++k2;
                    if (x >= 0)
                        break;
                }
            }
            if (mini_right + current >= 0 && k2 != -1)
            {
                while (right != k2)
                {
                    current += arr[right];
                    ++right;
                }
                right = k2;
                mini_right = 0;
                k2 = -1;
                continue;
            }
            break;
        }
        (left <= 0 || right > n) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}