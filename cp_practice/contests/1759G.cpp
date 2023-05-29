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

        int n;
        cin >> n;

        set<int> uniq;

        rp(i, 1, n + 1) uniq.insert(i);

        int arr[n / 2];

        rp(i, 0, n / 2)
        {
            cin >> arr[i];
            uniq.erase(arr[i]);
        }

        if (sz(uniq) != n / 2)
        {
            cout << "-1\n";
            continue;
        }

        bool check = true;
        deque<int> num;
        set<int> ele;

        for (auto i : uniq)
        {
            num.pb(i);
            ele.insert((-i));
        }

        int poss[n / 2], ans[n / 2];

        rp(i, 0, n / 2)
        {
            auto itr = upper_bound(all(num), arr[i]);
            if (itr == num.begin())
            {
                check = false;
                break;
            }
            --itr;
            poss[i] = (*itr);
        }

        if (!check)
        {
            cout << "-1\n";
            continue;
        }

        rep(i, n / 2 - 1, 0)
        {
            auto itr = ele.lower_bound((-poss[i]));
            if (itr == ele.end())
            {
                check = false;
                break;
            }
            ans[i] = -(*itr);
            ele.erase(itr);
        }

        if (!check)
        {
            cout << "-1\n";
            continue;
        }
        rp(i, 0, n/2)
        {
            cout << ans[i] << " " << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}