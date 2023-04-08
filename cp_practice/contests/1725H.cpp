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

int digits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n % 10);
        n /= 10;
    }
    return (ans % 3);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;

    while (t--)
    {

        int n;
        cin >> n;

        int arr[n];
        string ans = "";

        deq index[3];

        rp(i, 0, n)
        {
            cin >> arr[i];
            int x = digits(arr[i]);
            index[x].pb(i);
            ans.pb('k');
        }
        int white = 0, black = 0;
        if (sz(index[0]) <= (n / 2))
        {
            cout << "0\n";
        }
        else
        {
            cout << "2\n";
        }

        for (auto i : index[0])
        {
            ans[i] = '0';
            white++;
            if(white>=(n/2))break;
        }
        rp(i, 0, n)
        {
            if (ans[i] == 'k')
            {
                if (white < (n / 2))
                {
                    white++;
                    ans[i] = '0';
                }
                else
                {
                    ans[i] = '1';
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}