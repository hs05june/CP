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

deq possible[2];
deq arr[2];
void create(int index, int z, int k)
{
    if (index == arr[k].size())
    {
        possible[k].pb(z);
        return;
    }

    create(index + 1, z | ((1LL) << (arr[k][index])), k);

    if (possible[k].size() == 202)
    {
        return;
    }

    create(index + 1, z, k);

    if (possible[k].size() == 202)
    {
        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int t = 1;
    cin >> t;

    for (int i = 2; i < 31; i++)
    {
        arr[0].pb(i);
    }
    for (int i = 31; i < 60; i++)
    {
        arr[1].pb(i);
    }

    create(0, 0, 0);
    create(0, 0, 1);

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int arr[n + 1][m + 1];
        int x = 0;

        int k = 0;

        for (int i = 1; i <= n; i++)
        {
            if (possible[0][k] == 0)
                ++k;
            int l = 0;
            for (int j = 1; j <= m; j += 2)
            {
                if (possible[1][l] == 0)
                    ++l;
                arr[i][j] = possible[0][k] + possible[1][l];
                arr[i][j + 1] = possible[0][k] + possible[1][l];
                ++l;
            }
            ++k;
        }

        set<int> various;

        for (int i = 1; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j += 2)
            {
                arr[i][j] += 0;
                various.insert(arr[i][j]);
                if (i + 1 <= n)
                {
                    arr[i + 1][j] += 1;
                    various.insert(arr[i + 1][j]);
                }
                if (j + 1 <= m)
                {
                    arr[i][j + 1] += 2;
                    various.insert(arr[i][j + 1]);
                }
                if (i + 1 <= n && j + 1 <= m)
                {
                    arr[i + 1][j + 1] += 3;
                    various.insert(arr[i + 1][j + 1]);
                }
            }
        }
        cout << sz(various) << "\n";
        rp(i, 1, n + 1)
        {
            rp(j, 1, m + 1)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}