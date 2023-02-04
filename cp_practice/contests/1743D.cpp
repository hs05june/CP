#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define deq vector<int>
#define sz(a) (int)a.size()
#define pb push_back
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    string a;
    cin >> a;

    int firstone = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            firstone = i;
            break;
        }
    }

    if (firstone == -1)
    {
        cout << "0\n";
        return 0;
    }

    int firstzero = n;

    rep(i, 0, n - 1)
    {
        if (a[i] == '0')
        {
            firstzero = min(firstzero, i);
        }
    }

    if ((n - firstzero) <= n / 2)
    {
        rp(i, 0, n)
        {
            cout << "1";
        }
        cout << "\n";
        return 0;
    }

    firstzero = n;

    rep(i, firstone, n - 1)
    {
        if (a[i] == '0')
        {
            firstzero = min(firstzero, i);
        }
    }

    if (firstzero == n)
    {
        for (int i = firstone; i < n; i++)
        {
            cout << a[i];
        }
        cout << "\n";
        return 0;
    }

    deq zeroes;

    rp(i, firstzero, n)
    {
        if (a[i] == '0')
        {
            zeroes.pb(i);
        }
    }

    deq gap;

    for (int i = 1; i < sz(zeroes); i++)
    {
        gap.pb(zeroes[i] - zeroes[0]);
    }

    set<int> can_be;

    rep(i, firstone, firstzero - 1)
    {
        can_be.insert(i);
    }

    for (auto i : gap)
    {
        deq to_remove;
        for (auto j : can_be)
        {
            if (a[i + j] == '0')
            {
                to_remove.pb(j);
            }
        }
        if (sz(to_remove) == sz(can_be))
            continue;
        for (auto j : to_remove)
        {
            can_be.erase(j);
        }
    }

    int start = *(can_be.begin());
    int l = n - firstzero;

    string daalo = "";
    rp(i, 0, l)
    {
        daalo.pb(a[i + start]);
    }
    int x = n - 1;
    for (int i = sz(daalo) - 1; i >= 0; i--)
    {
        if (a[x] == '0' && daalo[i] == '1')
            a[x] = '1';
        --x;
    }

    for (int i = firstone; i < n; i++)
    {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}