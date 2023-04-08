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

        string a;
        cin >> a;

        int n = sz(a);

        if (n & 1)
        {
            cout << "NO\n";
            continue;
        }

        map<char, int> cnt;
        cnt['('] = 0;
        cnt['?'] = 0;
        cnt[')'] = 0;
        bool check = true;

        for (auto i : a)
        {
            cnt[i]++;
            if (cnt[')'] > cnt['?'] + cnt['('])
            {
                check = false;
            }
        }

        int open = n / 2 - cnt['('], close = n / 2 - cnt[')'];
        cnt['?'] = 0;
        cnt['('] = 0;
        cnt[')'] = 0;

        rep(i, n - 1, 0)
        {
            cnt[a[i]]++;
            if (cnt['('] > cnt['?'] + cnt[')'])
            {
                check = false;
            }
        }

        if ((!check) || (cnt['('] > n / 2) || (cnt[')'] > n / 2))
        {
            cout << "NO\n";
            continue;
        }

        if (close == 0 || open == 0)
        {
            cout << "YES\n";
            continue;
        }

        string b = a;
        int h = open;
        deq index;
        rp(i, 0, n)
        {
            if (b[i] == '?')
            {
                index.pb(i);
                if (open > 0)
                {
                    b[i] = '(';
                    open--;
                }
                else
                {
                    b[i] = ')';
                    close--;
                }
            }
        }

        b[index[h - 1]] = ')';
        b[index[h]] = '(';

        cnt['('] = 0;
        cnt[')'] = 0;
        for (auto i : b)
        {
            cnt[i]++;
            if (cnt[')'] > cnt['('])
                check = false;
        }

        (!check) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}