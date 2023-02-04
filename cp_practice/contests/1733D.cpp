#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int, int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
int M = 1000000007;
using namespace std;

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n, x, y;
        cin >> n >> x >> y;

        string a, b;

        cin >> a >> b;

        deq change;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                change.push_back(i);
            }
        }

        if (change.size() % 2 != 0)
        {
            cout << "-1\n";
            continue;
        }

        if (change.size() == 0)
        {
            cout << "0\n";
            continue;
        }

        ll ans = 0;

        if (change.size() > 2)
        {
            ans += (change.size() / 2) * y;
        }
        else if (change.size() == 2)
        {
            if (change[1] - change[0] > 1)
                ans += y;
            else
                ans += min(x, 2 * y);
        }

        cout << ans << "\n";
    }

    return 0;
}