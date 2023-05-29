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

map<char, int> get_count(string a)
{
    map<char, int> ans;
    ans['i'] = ans['w'] = ans['n'] = 0;
    for (auto i : a)
    {
        ans[i]++;
    }
    return ans;
}

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

        int n;
        cin >> n;

        string allstring[n];

        rp(i, 0, n) { cin >> allstring[i]; }

        deq edges[6];
        pair<char, char> store[6] = {{'w', 'i'}, {'i', 'w'}, {'i', 'n'}, {'n', 'i'}, {'w', 'n'}, {'n', 'w'}};

        int turn[2][3] = {{0, 2, 5}, {1, 4, 3}};

        rp(i, 0, n)
        {
            auto cnt = get_count(allstring[i]);
            rp(j, 0, 6)
            {
                if (cnt[store[j].f] > 1 && cnt[store[j].s] == 0)
                    edges[j].pb(i);
            }
        }

        vector<pair<pair<char, int>, pair<char, int>>> ans;
        rp(i, 0, 6)
        {
            int x = min(sz(edges[i]), sz(edges[i + 1]));
            while (x--)
            {
                ans.pb({{store[i].f, edges[i].back()}, {store[i].s, edges[i + 1].back()}});
                edges[i].pop_back();
                edges[i + 1].pop_back();
            }
            ++i;
        }

        rp(i, 0, 2)
        {
            int x = sz(edges[turn[i][0]]);
            while (x--)
            {
                ans.pb({{store[turn[i][0]].f, edges[turn[i][0]].back()}, {store[turn[i][0]].s, edges[turn[i][1]].back()}});
                ans.pb({{store[turn[i][0]].f, edges[turn[i][1]].back()}, {store[turn[i][1]].s, edges[turn[i][2]].back()}});
                edges[turn[i][0]].pop_back();
                edges[turn[i][1]].pop_back();
                edges[turn[i][2]].pop_back();
            }
        }

        cout << sz(ans) << "\n";
        for (auto i : ans)
        {
            cout << i.f.s + 1 << " " << i.f.f << " " << i.s.s + 1 << " " << i.s.f << "\n";
        }
    }

    return 0;
}