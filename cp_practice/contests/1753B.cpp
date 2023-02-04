//							  ੴ  ਵਾਹਿਗੁਰੂ

#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
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

    int n, k;
    cin >> n >> k;

    mii cnt;
    int a[n];
    rp(i, 0, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (auto i : cnt)
    {
        ll z = i.f + 1;
        ll x = i.s / z;
        if (x != 0)
        {
            cnt[i.f + 1] += x;
            cnt[i.f] -= z * x;
        }
    }

    int x = 0;
    bool check = true;
    set<int> all_ele;

    for (auto i : cnt)
    {
        if (i.s != 0)
        {
            all_ele.insert(i.f);
        }
    }

    for (auto i : all_ele)
    {
        if (i < k)
        {
            check = false;
        }
    }

    check ? cout << "YES\n" : cout << "NO\n";

    return 0;
}