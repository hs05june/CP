#include <bits/stdc++.h>
#define rp(i, a, n) for (int i = a; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
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

        string a[n];
        int arr[n][n] = {0};

        int sum = 0;
        rp(i, 0, n) cin >> a[i];
        rp(i, 0, n)
        {
            rp(j, 0, n)
            {
                arr[i][j] = (int)(a[i][j] - '0');
                sum += arr[i][j];
            }
        }

        int kaam_ke = 0;

        rp(i, 0, n)
        {
            int x1 = i, y1 = 0;
            int z1 = 0, z2 = 0;
            while (z2 < n)
            {
                if (arr[x1][y1] == 1)
                    z1++;
                x1++;
                y1++;
                x1 %= n;
                y1 %= n;
                z2++;
            }

            kaam_ke = max(kaam_ke, z1);
        }
        cout << (sum - kaam_ke + n - kaam_ke) << "\n";
    }

    return 0;
}