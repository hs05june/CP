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

        int n;
        cin >> n;

        int a[n];
        cin >> a[0];
        int rem[4] = {2, 4, 8, 6};
        a[0] += (a[0] % 10);
        int maxi = a[0], k = 0;

        bool check = true, five_zero = false;

        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            a[i] += (a[i] % 10);
            if (maxi < a[i])
            {
                maxi = a[i];
                k = i;
            }
            if ((a[i] % 10) == 0)
            {
                five_zero = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] != maxi)
                check = false;
        }

        if (check)
        {
            cout << "YES\n";
            continue;
        }

        if (five_zero)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            while ((a[i] % 10) != (maxi % 10) && x < 4)
            {
                a[i] += (a[i] % 10);
                ++x;
            }
        }

        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            if ((maxi - a[i]) % 20 != 0)
                ans = false;
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}