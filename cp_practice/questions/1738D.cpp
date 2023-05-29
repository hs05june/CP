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

        int arr[n + 1], cnt[n + 2], preffix[n + 2];
        rp(i, 0, n + 2) cnt[i] = 0;
        bool check1 = false, check2 = false;
        rp(i, 1, n + 1)
        {
            cin >> arr[i];
            if (arr[i] == 0)
                check1 = true;
            if (arr[i] == n + 1)
                check2 = true;
            cnt[arr[i]]++;
        }

        preffix[0] = cnt[0];

        rp(i, 1, n + 2) preffix[i] = preffix[i - 1] + cnt[i];

        int k = 0;
        rp(i, 1, n + 1)
        {
            if (preffix[i] == (n - i))
            {
                k = i;
                break;
            }
        }

        map<int, deq> ele;
        deq ans1, ans2;
        for (int i = 1; i <= n; i++)
        {
            ele[arr[i]].pb(i);
        }

        deq ans;
        int x = check1 ? 0 : n + 1;
        while (true)
        {
            int hj = 0;
            for (auto i : ele[x])
            {
                if (ele[i].empty())
                {
                    ans.pb(i);
                }
                else
                {
                    hj = i;
                }
            }
            if (hj == 0)
                break;
            ans.pb(hj);
            x = hj;
        }
        cout << k << "\n";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}