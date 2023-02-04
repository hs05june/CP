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
#define lb(a, b) lower_bound((a).begin(), (a).end(), c)
const ll M = 1000000007;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while (t--)
    {

        map<char, int> a, b;
        a['a'] = 1;
        b['a'] = 1;

        for (char i = 'b'; i <= 'z'; i++)
        {
            a[i] = 0;
            b[i] = 0;
        }

        int al = 1, bl = 1;

        int q;
        cin >> q;

        while (q--)
        {
            int test;
            cin >> test;
            if (test == 1)
            {
                int k;
                string x;
                cin >> k;
                cin >> x;
                al += (x.length() * k);
                map<char, int> to_add;
                rp(i, 0, x.length())
                {
                    to_add[x[i]]++;
                }
                for (char i = 'a'; i <= 'z'; i++)
                {
                    a[i] += (to_add[i] * k);
                }
            }
            if (test == 2)
            {
                int k;
                string x;
                cin >> k;
                cin >> x;
                bl += (x.length() * k);
                map<char, int> to_add;
                rp(i, 0, x.length())
                {
                    to_add[x[i]]++;
                }
                for (char i = 'a'; i <= 'z'; i++)
                {
                    b[i] += (to_add[i] * k);
                }
            }

            int ax = al, bx = bl;
            bool ans = true;

            char maxi = 'a', mini = 'z';
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (a[i] != 0)
                {
                    mini = i;
                    break;
                }
            }
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (b[i] != 0)
                {
                    maxi = i;
                }
            }
            if (maxi > mini)
            {
                ans = true;
            }
            else if (mini > maxi)
            {
                ans = false;
            }
            else if (maxi == mini)
            {
                if (a[mini] != al || a[mini] > b[maxi] || (a[mini] == b[maxi] && bl == b[maxi]))
                {
                    ans = false;
                }
                else
                {
                    ans = true;
                }
            }
            ans ? cout << "YES\n" : cout << "NO\n";
        }
    }

    return 0;
}