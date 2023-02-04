#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define si set<ll>
#define pb push_back
#define f first
#define s second
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);cout.tie(0);
#define HARPREET cout << fixed << setprecision(20);
const ll M = 1000000007;
using namespace std;

signed main()
{
    CODE BY HARPREET

        int n,
        m;
    cin >> n >> m;

    map<int,multiset<ll>> rows,cols;
    int a[n][m];
    si ele;

    rp(i, 0, n)
    {
        rp(j, 0, m)
        {
            cin >> a[i][j];
            ele.insert(a[i][j]);
            rows[a[i][j]].insert(i+1);
            cols[a[i][j]].insert(j+1);
        }
    }
    ll ans = 0;

    for(auto i : rows){
        ll j = 0;
        for(auto k : i.s){
            ans += (2*j+1-sz(i.s))*k;
            ++j;
        }
    }
    for(auto i : cols){
        ll j = 0;
        for(auto k : i.s){
            ans += (2*j+1-sz(i.s))*k;
            ++j;
        }
    }

    cout << ans << "\n";

    return 0;
}