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

        int n;
        cin >> n;
        bool x = true;
        int arr[n];
        cin >> arr[0];
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            if (arr[0] != arr[i])
                x = false;
        }

        if (n == 1 || x)
        {
            cout << "0\n";
            continue;
        }

        deque<pii> ans;
        ans.push_back({1, n});
        if ((arr[0] + arr[n - 1]) % 2 == 0)
        {
            arr[0] = arr[n - 1];
            for (int i = 1; i < n - 1; i++)
            {
                if ((arr[i] + arr[n - 1]) % 2 == 0)
                {
                    ans.push_back({i + 1, n});
                }
                else
                {
                    ans.push_back({1, i + 1});
                }
            }
        }
        else
        {
            arr[n - 1] = arr[0];
            for (int i = 1; i < n - 1; i++)
            {
                if ((arr[i] + arr[0]) % 2 != 0)
                {
                    ans.push_back({1, i + 1});
                }
                else
                {
                    ans.push_back({i + 1, n});
                }
            }
        }
        cout << ans.size() << "\n";

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }

    return 0;
}