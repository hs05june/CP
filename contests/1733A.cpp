#include <bits/stdc++.h>
#define ll long long
#define CODE ios_base::sync_with_stdio(0);
#define BY cin.tie(0);
#define HARPREET cout.tie(0);
#define int long long
using namespace std;

signed main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int arr[n], ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxi[k] = {0};
        for (int i = 0; i < k; i++)
        {
            for (int j = i; j < n; j += k)
            {
                maxi[i] = max(maxi[i], arr[j]);
            }
        }

        for (int i = 0; i < k; i++)
        {
            ans += maxi[i];
        }
        cout << ans << "\n";
    }

    return 0;
}