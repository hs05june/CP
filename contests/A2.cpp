#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
int M = 1000000007;
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll s = 0, e = 0, ans = 0;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        ans += abs(x - s) + abs(y - e);
        s = x, e = y;
    }

    ans += abs(s) + abs(e);
    cout << ans << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}