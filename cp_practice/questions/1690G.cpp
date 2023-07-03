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

int n;
int fenwick[100007];

void update(int ind, int x)
{
    for (int i = ind; i <= n; i += (i & (-i)))
    {
        fenwick[i] += x;
    }
}

int sum(int ind)
{
    int ans = 0;
    for (int i = ind; i > 0; i -= (i & (-i)))
    {
        ans += fenwick[i];
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

        int m;
        cin >> n >> m;
        rp(i, 0, n + 1) fenwick[i] = 0;

        int arr[n + 1];
        arr[0] = 0;

        rp(i, 1, n + 1) cin >> arr[i];

        set<pair<int, pii>> uniq;
        rp(i, 1, n + 1)
        {
            int mini = arr[i];
            int start = i;
            while (i <= n && mini <= arr[i])
            {
                ++i;
            }
            --i;
            uniq.insert({-mini, {start, i}});
        }

        for (auto i : uniq)
        {
            int x = -i.f, y1 = i.s.f, y2 = i.s.s;
            update(y1, x);
            update(y2 + 1, -x);
        }

        while (m--)
        {
            int k, d;
            cin >> k >> d;

            int speed = sum(k);
            arr[k] -= d;
            if (arr[k] >= speed)
            {
                cout << sz(uniq) << " ";
                continue;
            }
            auto itr = uniq.lower_bound({-speed, {0, 0}});
            int x = (*itr).s.f, y = (*itr).s.s;
            uniq.erase(itr);
            update(x, -speed);
            update(y + 1, speed);
            if (k - 1 >= x)
            {
                uniq.insert({-speed, {x, k - 1}});
                update(x, speed);
                update(k, -speed);
            }
            auto itr1 = uniq.upper_bound({-speed, {n + 1, n + 1}});
            auto itr2 = uniq.upper_bound({-arr[k], {n + 1, n + 1}});
            int last = (itr2 == uniq.end()) ? n : (*itr2).s.f - 1;
            while (itr1 != uniq.upper_bound({-arr[k], {n + 1, n + 1}}))
            {
                int x1 = -(*itr1).f, y1 = (*itr1).s.f, z1 = (*itr1).s.s;
                update(y1, -x1);
                update(z1 + 1, x1);
                uniq.erase(uniq.find({-x1, {y1, z1}}));
                itr1 = uniq.upper_bound({-speed, {n + 1, n + 1}});
            }
            update(k, arr[k]);
            update(last + 1, -arr[k]);
            uniq.insert({-arr[k], {k, last}});
            cout << sz(uniq) << " ";
        }
        cout << "\n";
    }

    return 0;
}