#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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

        string a;
        cin >> a;

        int k;
        cin >> k;

        int use[a.length()] = {0};
        deq left;

        char mini = '9';
        int index = 0;

        for (int i = 0; i <= k; i++)
        {
            if (a[i] < mini && a[i] != '0')
            {
                mini = a[i];
                index = i;
            }
        }

        for (int i = 0; i < index; i++)
        {
            use[i] = 1;
            --k;
        }

        int start = index + 1, end = index + 1;

        while (k > 0)
        {
            int prev = k;
            if (start >= index + 1 && a[start] > a[end])
            {
                use[start] = 1;
                left.pop_back();
                if (sz(left) > 0)
                {
                    start = left.back();
                }
                else
                {
                    start = end;
                }
                --k;
                continue;
            }
            start = end;
            for (int i = start; i < a.length() - 1; i++)
            {
                if (a[i] > a[i + 1])
                {
                    use[i] = 1;
                    --k;
                    if (sz(left) > 0)
                    {
                        start = left.back();
                        end = i + 1;
                    }
                    else
                    {
                        start = i + 1;
                        end = i + 1;
                    }
                    break;
                }
                left.pb(i);
            }
            if (prev == k)
                break;
        }

        for (int i = a.length() - 1; i >= 0 && k > 0; i--)
        {
            if (use[i] == 0)
            {
                use[i] = 1;
                --k;
            }
        }

        rp(i, 0, a.length())
        {
            if (use[i] == 0)
                cout << a[i];
        }
        cout << "\n";
    }

    return 0;
}