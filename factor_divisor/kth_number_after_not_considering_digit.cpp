// All the numbers containing digit 4 have been removed, You have to find kth number in that number system

// Solution - Removing a digit means you ar left with a base-9 number system, SO convert decimal number to base 9
// And print the answer, But now the sequence of digits gets changed

// 0th digit = 0
// 1st digit = 1
// 2nd digit = 2
// 3rd digit = 3
// 4th digit = 5
// 5th digit = 6
// 6th digit = 7
// 7th digit = 8
// 8th digit = 9

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

    int k;
    cin >> k;

    int num[9] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    string ans = "";

    int x = 1;
    while (x <= k)
        x *= 9;

    x /= 9;
    while (x > 0)
    {
        int z = k / x;
        k -= (z * x);
        char po = (char)(num[z] + (int)'0');
        ans.pb(po);
        x /= 9;
    }

    cout << ans << "\n";

    return 0;
}