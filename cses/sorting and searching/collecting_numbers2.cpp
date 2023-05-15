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

    int n, m;
    cin >> n >> m;

    int arr[n + 1], index[n + 2];
    index[0] = 0;
    arr[0] = 0;
    index[n + 1] = n + 1;

    rp(i, 1, n + 1)
    {
        cin >> arr[i];
        index[arr[i]] = i;
    }

    int ans = 1;
    int in = index[1];
    rp(i, 1, n + 1)
    {
        if (index[i] < in)
            ans++;
        in = index[i];
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int x = arr[a], y = arr[b];
        // cout << x << " " << y << " ";
        swap(arr[a], arr[b]);
        if (abs(x - y) == 1)
        {
            if (x > y)
                swap(x, y);
            if (index[x] > index[y])
            {
                ans--;
                // cout << "a ";
            }
            if (index[x] < index[y])
            {
                ans++;
                // cout << "b ";
            }
            if (index[x] > index[x - 1] && index[y] < index[x - 1])
            {
                ans++;
                // cout << "c ";
            }
            if (index[y] < index[y + 1] && index[x] > index[y + 1])
            {
                ans++;
                // cout << "d ";
            }
            if (index[x] < index[x - 1] && index[y] > index[x - 1])
            {
                ans--;
                // cout << "e ";
            }
            if (index[y] > index[y + 1] && index[x] < index[y + 1])
            {
                ans--;
                // cout << "f ";
            }
        }
        if (abs(x - y) != 1)
        {
            if (index[x - 1] < index[x] && index[x - 1] > index[y])
            {
                ans++;
                // cout << "1 ";
            }
            if (index[x + 1] > index[x] && index[x + 1] < index[y])
            {
                ans++;
                // cout << "2 ";
            }
            if (index[x - 1] > index[x] && index[x - 1] < index[y])
            {
                ans--;
                // cout << "3 ";
            }
            if (index[x + 1] < index[x] && index[x + 1] > index[y])
            {
                ans--;
                // cout << "4 ";
            }
            if (index[y - 1] < index[y] && index[y - 1] > index[x])
            {
                ans++;
                // cout << "5 ";
            }
            if (index[y + 1] > index[y] && index[y + 1] < index[x])
            {
                ans++;
                // cout << "6 ";
            }
            if (index[y - 1] > index[y] && index[y - 1] < index[x])
            {
                ans--;
                // cout << "7 ";
            }
            if (index[y + 1] < index[y] && index[y + 1] > index[x])
            {
                ans--;
                // cout << "8 ";
            }
        }
        swap(index[x], index[y]);
        cout << ans << "\n";
    }

    return 0;
}