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

int power(int a, int b, int mod)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans % mod * 1LL * a % mod) % mod;
        }
        a = (a % mod * 1LL * a % mod) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    CODE BY HARPREET

        int t;
    cin >> t;

    while (t--)
    {

        int n, x, y;
        cin >> n >> x >> y;

        int a = max(x, y), b = min(x, y), m = n - 1;
        bool ans = false;
        if (b == 0 && a == 0)
        {
            cout << "-1\n";
            continue;
        }
        else if (b == 0 && m % a != 0)
        {
            cout << "-1\n";
            continue;
        }
        else if (b == 0 && m % a == 0)
        {
            for (int i = 1; i < n; i += a)
            {
                int z = 0;
                while (z < a)
                {
                    cout << i + 1 << " ";
                    ++z;
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}